#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

List *create_list() {
    List *new_list = (List *)malloc(sizeof(List));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

int is_empty(List *list) {
    return list->size ? 0 : 1;
}

int get_size(List *list) {
    return list->size;
}

void insert_into_list(List *list, int elem) {
    if(list == NULL) return;

    Node *new_node = (Node *)malloc(sizeof(Node));
    
    new_node->next = NULL;
    new_node->data = elem;

    if(is_empty(list)) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void print_list(List *list) {
    if(is_empty(list) || list == NULL) return;

    Node *p = list->head; /* makes the p Node iterate through the list */
    for(p; p != NULL; p = p->next)
        if(p->next == NULL) 
            printf("%d ", p->data);
        else
            printf("%d, ", p->data);
    printf("\n");
}

int search_list(List *list, int elem){
    if(is_empty(list) ||list == NULL) return -1;

    int iterations = 0;
    Node *p;
    
    for(p = list->head; p != NULL; p = p->next, iterations++) 
        if(p->data == elem) return iterations;

    return -1;
}   

void destroy_list(List *list) {

}
