#pragma once 

#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef enum boolean{false, true} Boolean;

typedef struct {
	int* vector;
	int length;
	int size;
}Stack;

Stack *create_stack();
void destroy_stack(Stack *s);
Boolean push_element(Stack *s, int data);
Boolean pop_element(Stack *s, int* mem_adress);
Boolean top_element(Stack *s, int* mem_adress);
void print(Stack *s);
int get_size(Stack *s);
Stack *clone_stack(Stack *s);
void revert_stack(Stack *s);
Boolean push_all_elements(Stack *s, int* vector, int lengthvector);
