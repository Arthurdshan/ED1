#include <stdlib.h>
#include "hashtable_oa.h"

int HTOA_Hash(HTOA *HT, int key, int k){
    return ((key % HT->m) + k) % HT->m;
}

HTOA* HTOA_create(int m){
    HTOA *new_ht = (HTOA*)malloc(sizeof(HTOA));
    new_ht->table = (Element*)malloc(sizeof(Element) * m);
    new_ht->m = m;
    for(int i = 0; i < m; i++)
        new_ht->table[i].status = empty;
    return new_ht;
}

int HTOA_insert(HTOA *HT, int key, int value){
    int h, k, initial_h;
    k = 0;
    h = HTOA_Hash(HT, key, k);
    initial_h = h;

    while(HT->table[h].status == occupied){
        if(HT->table[h].key == key){
            break;
        }
        k++;
        h = HTOA_Hash(HT, key, k);
        if (h == initial_h) return -1;    
    }

    HT->table[h].key = key;
    HT->table[h].value = value;
    HT->table[h].status = occupied;

    return h;
}
/**
 * h is for the hash
 * initial h is to verify if the hash table was iterated to the end  
*/
int HTOA_search(HTOA *HT, int key){
    int h,  initial_h, k;
    k = 0;
    h = HTOA_Hash(HT, key, k);
    initial_h = h;
    
    while(HT->table[h].status != empty){
        if((HT->table[h].status == occupied) && (HT->table[h].key == key))
            return h;
       
        k++;
       
        h = HTOA_Hash(HT, key, k);
        if(initial_h == h) return -1;
    }
    return -1;
}

void HTOA_remove_element(HTOA *HT, int key){
    int p = HTOA_search(HT, key);
    if (p != -1) HT->table[p].status = wiped;
}

void HTOA_destroy(HTOA *HT){
    free(HT->table);
    free(HT);
}