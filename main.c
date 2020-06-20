#include <stdio.h>
#include "list.h"

int main(){
    List list = newList();
    printf("\t1. addHead(list,item)\n"
           "\t2. removeHead(list)\n"
           "\t3. getHead\n"
           "\t4. searchList\n"
           "\t5. removeListItem\n"
           "\t6. removeListItemPos\n"
           "\t7. addListItem\n"
           "\t8. addListTail\n"
           "\t9. reverseList\n"
           "\t0. cloneList\n"
           "\t-1. selectionSort\n"
           "\t-2. insertionSort\n"
           "\t-2. bubbleSort\n");
    while(1){
        if(!isEmpty(list))
            printf("\tElementi in lista: %d\n",sizeList(list));
        else
            printf("\tLista vuota\n");
        printList(list);
        printf("\n");
        printf("\tInserisci opzione: ");
        int n;
        scanf("%d",&n);
        switch(n){
        case 1:
        {
            addHead(list, inputItem());
            break;
        }
        case 2:
        {
            removeHead(list);
            break;
        }
        case 3:
        {
            getHead(list);
            break;
        }
        case 4:
        {
            int pos;
            if(searchList(list, inputItem(), &pos))
                printf("trovato in posizione %d\n", pos);
            else
                printf("non trovato\n");
            break;
        }
        case 5:
        {
            Item item = removeListItem(list, inputItem());
            if(!item)
                printf("non trovato\n");
            else
                printf("trovato e rimosso\n");
            break;
        }
        case 6:
        {
            int pos;
            scanf("%d", &pos);
            Item item = removeListItemPos(list,pos);
            if(!item)
                printf("non trovato\n");
            else
                printf("trovato e rimosso\n");
            break;
        }
        case 7:
        {
            int pos;
            scanf("%d",&pos);
            addListItem(list, inputItem(), pos);
            break;
        }
        case 8:
        {
            addListTail(list, inputItem());
            break;
        }
        case 9:
        {
            reverseList(list);
            break;
        }
        case 0:
        {
            list = cloneList(list);
            break;
        }
        case -1:
        {
            selectionSort(list);
            break;
        }
        case -2:
        {
            insertionSort(list);
            break;
        }
        case -3:
        {
            bubbleSort(list);
            break;
        }
        }
    }


}
