#pragma once

#include "ilist.h"

typedef struct HT {
    ILIST** t;
    int m;
} HT;

HT* HT_create(int m, int alloc_step);
int HT_hash(HT* HT, int key);
void HT_insert(HT* HT, int key, int valor);
void HT_destroy(HT* HT);
void HT_destroy_list(ILIST * i);
NODE* HT_search(HT* HT, int key);
HT* insert_random_n(int n, int m, int seed);
int HT_largest(HT* TH);
int HT_smallest(HT* TH);
float HT_medium_size(HT* TH);