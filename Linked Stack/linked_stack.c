#include <stdio.h>
#include <stdlib.h>
#include "linked_stack.h"

Stack *create_stack(){
  Stack *s = (Stack*) malloc(sizeof(Stack));
  s->size = 0;
  return s;
}

void destroy_stack(Stack* s){
  Node *temp = s->top;
  Node *aux;
    for(int i = 0; i < s->size; i++){
      aux = temp;
      temp = temp->next;
      free(aux);
    }
  free(s);
}

Boolean push_element(Stack* s, int data){
  if(s == NULL) return false;
  
  Node *node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->next = s->top;
  s->size++;
  s->top = node;
  return true;
}

Boolean pop_element(Stack *s, int *mem_adress){
  if(s == NULL || s->top == NULL) return false;

  *mem_adress = s->top->data;
  Node *aux = s->top;
  s->top = aux->next;
  s->size--; 
  free(aux);
  return true;
}

void print(Stack* s){
  Node* aux = s->top;
  for(int i = 0; i < s->size; i++){
    printf("%d -> ", aux->data);
    aux = aux->next;
  }
  free(aux);
  printf("NULL\n");
}

Boolean top_element(Stack *s, int *mem_adress){
  if (s == NULL || s->top == NULL) return false;

  *mem_adress = s->top->data;
  return true; 
}

int get_size(Stack *s){
  return s->size;
}

Stack *clone_stack(Stack *s){
  Stack *clone = (Stack*) malloc(sizeof(Stack));
  Node *traversal = s->top;
  Node *temp;
  for(int i = 0; i < s->size; i++){
    Node *data = (Node*) malloc(sizeof(Node));
    data->data = traversal->data;
      
    if(i == 0) clone->top = data;
    else temp->next = data;
      
    temp = data;
    traversal = traversal->next;
  }
  return clone;
}

void revert_stack(Stack* s){
  Stack* p1 = create_stack();
  Node* aux = s->top;
  while(aux != NULL){
    push_element(p1,aux->data);
    aux = aux->next;
  }
  p1->size = s->size;
  s->top = p1->top;
}

Boolean push_all_elements(Stack *s, int *vector, int size){
  if (s == NULL) return false;

  for(int i = 0; i < size; i++){
    int aux = vector[i];
    push_element(s, aux);
    s->size++;
  }
  return true;
}