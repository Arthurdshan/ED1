#pragma once

// Hash table cell status
typedef enum status {
    empty,
    occupied,
    wiped
} Status;

// elements from the HT
typedef struct element {
    int key;
    int value;
    Status status;
} Element;

// HTOA stands for hash table open adressing
typedef struct HTOA {
    int m;
    int n;
    Element *table;
} HTOA;

int HTOA_Hash(HTOA *HT, int key, int k);
HTOA* HTOA_create(int m);
int HTOA_insert(HTOA *HT, int key, int value);
int HTOA_search(HTOA *HT, int key);
void HTOA_remove_element(HTOA *HT, int key);
void HTOA_destroy(HTOA *HT);
