#pragma once

/* a linked list that uses double pointers*/

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list { 
    int size;
    Node *head; 
    Node *tail; 
} List;

List *create_list();
int is_empty(List *list);
int get_size(List *list);
void insert_into_list(List *list, int elem);
void destroy_list(List *list);
void print_list(List *list);
int search_list(List *list, int elem);