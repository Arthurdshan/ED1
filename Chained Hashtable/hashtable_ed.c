#include <stdlib.h>
#include <limits.h>

#include "ilist.h"
#include "hashtable_ed.h"

int HT_hash(HT* HT, int key){
    return key % HT->m;
}

HT* HT_create(int m, int alloc_step){
    HT *new;
    int i;

    new = malloc(sizeof(HT));
    new->m = m;
    new->t = malloc(sizeof(ILIST*) * m);
    for(i = 0; i < m; i++)
        new->t[i] = ILIST_create(alloc_step);

    return new;
}

void HT_insert(HT* HT, int key, int valor){
    int h;
    h = HT_hash(HT, key);
    ILIST_insert(HT->t[h], key, valor);
}

void HT_destroy_list(ILIST * i){
    free(i->node);
    free(i);
}

void HT_remove_element(HT* HT, int key){
    int hash = HT_hash(HT, key);
    ILIST_remove(HT->t[hash], key);
}

void HT_destroy(HT* HT){
    for(int i = 0; i < HT->m; i++) {
        ILIST* aux_list = HT->t[i];
        if(aux_list != NULL) {
            HT_destroy_list(aux_list);
        }
    }
    free(HT->t);
    free(HT);
}

NODE* HT_search(HT* HT, int key){
    int h, pos;
    h = HT_hash(HT, key);
    pos = ILIST_search(HT->t[h], key);
    return ILIST_mem_adress(HT->t[h], pos);
}
    
HT* insert_random_n(int n, int m, int seed){
    HT *HT = HT_create(m, n);
    srand(seed);
    for(int i = 0; i < n; i++) {
        int elemento_aleatorio = rand() % (n * 10);
        HT_insert(HT, elemento_aleatorio, elemento_aleatorio);
    }
    return HT;
}

int HT_largest(HT* HT){
    int largest = HT->t[0]->tam;
    for(int i = 1; i < HT->m; i++)
        if(HT->t[i]->tam > largest)
            largest = HT->t[i]->tam;
   return largest;
}

int HT_smallest(HT* HT){
    int smallest = HT->t[0]->tam;
    for(int i = 1; i < HT->m; i++)
        if(HT->t[i]->tam < smallest)
            smallest = HT->t[i]->tam;
    return smallest;
}

float HT_medium_size(HT* HT){
    int medium_size = 0;
    for(int i = 0; i < HT->m; i++)
        medium_size += HT->t[i]->tam;
    return (float) medium_size / HT->m;
}