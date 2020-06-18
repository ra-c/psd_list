#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(){
    int* n = malloc(sizeof(int));
    scanf("%d", n);
    return n;
}

void outputItem(Item item){
    printf("%d ", *((int*)item));
}

int cmpItem(Item n1, Item n2){
    return *((int*)n1) - *((int*)n2);
}

Item cloneItem (Item n){
    int* clone = malloc(sizeof(int));
    *clone = *((int*)n);
    return clone;
}
