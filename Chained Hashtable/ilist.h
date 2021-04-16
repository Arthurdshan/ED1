#pragma once

typedef struct NODE{
    int key;
    int valor;
    int taken;
} NODE;

typedef struct ILIST{
    NODE *node;
    int max;
    int tam;
    int alloc;
    int alloc_step;
} ILIST;

ILIST* ILIST_create(int alloc_step);
int ILIST_insert(ILIST *L, int key, int valor);
int ILIST_remove(ILIST *L, int key);
int ILIST_search(ILIST *L, int key);
void ILIST_print(ILIST *L, int debug);
NODE* ILIST_mem_adress(ILIST *L, int pos);
