#include "ilist.h"
#include <stdlib.h>
#include <stdio.h>

ILIST* ILIST_create(int alloc_step){
    ILIST* new;
    int i;

    new = malloc(sizeof(ILIST));

    new->alloc = alloc_step;
    new->alloc_step = alloc_step;
    new->max = 0;
    new->tam = 0;
    new->node = malloc(sizeof(NODE) * new->alloc);

    for(i = 0; i < new->alloc; i++){
        new->node[i].taken = 0;
    }

    return new;

}

int ILIST_insert(ILIST *L, int key, int valor){
    int i;
    int empty;
    empty = -1;

    for(i = 0; i < L->max; i++){
        if( (L->node[i].key == key) && L->node[i].taken){
            empty = -1;
            L->tam--;
            break;
        }
        if(L->node[i].taken == 0){
            if (empty == -1)
                empty = i;
        }
    }

    if(empty != -1)
        i = empty;

    if(i >= L->max)
        L->max++;
        
    if( i >= L->alloc ){
        L->alloc = L->alloc + L->alloc_step;
        L->node = realloc(L->node, sizeof(NODE) * L->alloc);
    }

    L->node[i].key = key;
    L->node[i].valor = valor;
    L->node[i].taken = 1;
    L->tam++;

    return i;
}

int ILIST_remove(ILIST *L, int key){
    int i;
    i = ILIST_search(L, key);
    
    if(i != -1){
        L->tam--;
        L->node[i].taken = 0;
    }

    return i;
}

int ILIST_search(ILIST *L, int key){
    int i;
    
    for(i = 0; i < L->max; i++){
        if( (L->node[i].key == key) && L->node[i].taken )
            return i;
    }
    
    return -1;

}

NODE* ILIST_mem_adress(ILIST *L, int pos){
    if(pos != -1)
        return &L->node[pos];
    return NULL;
}

void ILIST_print(ILIST *L, int debug){
    int i;

    printf("TAM: %d, MAX: %d\n", L->tam, L->max);

    for(i = 0; i < L->max; i++){
        if (L->node[i].taken || debug)
            printf("%d -> %d (%d) \n", L->node[i].key, L->node[i].valor, L->node[i].taken);
    }

}
