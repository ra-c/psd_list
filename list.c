#include <stdlib.h>
#include "item.h"
#include "list.h"

typedef struct node* Node;

struct node{
    Item item;
    Node next;
};

struct list{
    int size;
    Node head;
};

List newList(){
    List list = malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;
    return list;
}

int isEmpty(List list){
    return (list->size <= 0 && list->head==NULL);
}

Node createNode(Item item, Node next){
    Node node = malloc(sizeof(struct node));
    node->item = item;
    node->next = next;
    return node;
}

void addHead(List list, Item item){
    Node prevHead = list->head;
    list->head = createNode(item, prevHead);
    list->size++;
}

Item removeHead(List list){
    if(!list->head)
        return NULL;
    Node head = list->head;
    Item item = head->item;
    list->head = head->next;
    free(head);
    list->size--;
    return item;
}

Item getHead(List list){
    if (!list->head)
        return NULL;
    return list->head->item;
}

int sizeList(List list){
    return list->size;
}

void printList(List list){
    Node n = list->head;
    while(n){
        outputItem(n->item);
        n = n->next;
    }
}

Item searchList(List list, Item item, int* pos){
    Node n = list->head;
    *pos = 0;
    while(n && *pos < list->size){
        if(cmpItem(n->item, item) == 0)
            return n->item;
        n=n->next;
        (*pos)++;
    }
    return NULL;
}

Item removeListItem(List list, Item item){
    Node n_prev = NULL;
    Node n      = list->head;
    while(n){
        if(cmpItem(n->item, item) == 0){
            if(!n_prev)
                return removeHead(list);
            n_prev->next = n->next;
            Item tmp = n->item;
            free(n);
            list->size--;
            return tmp;
        }
        n_prev = n;
        n = n->next;
    }
    return NULL;
}

Item removeListItemPos(List list, int pos){
    if(pos<0 || pos >= list->size)
        return NULL;
    if(pos==0)
        return removeHead(list);

    Node n = list->head;
    int i = 0;
    while(i<pos-1){
        n = n->next;
        i++;
    }
    Node tmp = n->next;
    Item item = tmp->item;
    n->next = tmp->next;
    free(tmp);
    list->size--;
    return item;
}

int addListItem(List list, Item item, int pos){
    if(pos<0 || pos > list->size)
        return 0;
    if(pos == 0){
        addHead(list,item);
        return 1;
    }

    int i=1;
    Node n = list->head;
    while(i<pos){
        n = n->next;
        i++;
    }
    n->next = createNode(item, n->next);
    list->size++;
    return 1;
}

int addListTail(List list, Item item){
    return addListItem(list, item, list->size);
}

void reverseList(List list){
    if(!list->head)
        return;
    Node head  = list->head;
    Node pre_n = list->head;
    Node     n = list->head->next;
    while(n){
        /* Nota:
         *      pre_n punta sempre allo stesso elemento
         *      head viene riposizionato sempre a indice 0
         *      n punterà sempre all'elemento successivo a pre_n */
        pre_n->next = n->next;
        n->next = head;
        head = n;
        n = pre_n->next;
    }
    list->head = head;
}

List cloneList(List list){
    List new_list = newList();
    Node n = list->head;
    Node* ptr_n_new = &(new_list->head);
    while(n){
        *ptr_n_new = n;
        n = n->next;
        ptr_n_new = &(*ptr_n_new)->next;
    }
    return new_list;
}

void freeList(List list){
    if(!list) return;
    while(!isEmpty(list))
        removeHead(list);
    free(list);
}

void swap(Item *a, Item *b){
    Item temp = *b;
    *b = *a;
    *a = temp;
}

Item minimo(Node head){
    if(!head)
        return NULL;
    Node n = head;
    Item min = n->item;
    while(n){
        if(cmpItem(n->item, min) < 0)
            min = n->item;
        n = n->next;
    }
    return min;
}

void selectionSort(List list){
    Node n = list->head;
    while(n){
        swap(n->item, minimo(n));
        n = n->next;
    }
}

void insertSorted(List list, Node unsorted){
    /* Nota: in questa funzione si suppone che il nodo unsorted non abbia nessun nodo precedente */
    if(!unsorted || !list)
        return;
    /* Lista vuota */
    if(!list->head){
        list->head = unsorted;
        unsorted->next = NULL;
        return;
    }
    /* Caso speciale: l'elemento unsorted viene posizionato al primo posto nella lista ordinata */
    if(cmpItem(unsorted->item, list->head->item)<0){
        unsorted->next = list->head;
        list->head = unsorted;
        return;
    }
    /* Caso comune */
    Node n = list->head;
    while(n->next && cmpItem(unsorted->item,n->next->item)>0)
        n = n->next;
    unsorted->next = n->next; /* n->next è il primo elemento maggiore di unsorted */
    n->next = unsorted;
    return;
}

void insertionSort(List list){
    if(!list->head || !list->head->next)
        return;
    /* Spezzo la lista in due liste: lista ordinata e lista non ordinata */
    Node n = list->head->next; 
    list->head->next = NULL;

    while(n){
        Node tmp = n;
        n = n->next;
        insertSorted(list, tmp);
    }
}
