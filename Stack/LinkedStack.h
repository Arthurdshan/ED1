#pragma once 

#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{FALSE, TRUE} Boolean;
typedef int DataType;

typedef struct node{
	DataType value;
	struct node *next;
}Node;

typedef struct {
	Node *top;
	int size;
}Stack;

Stack* createStack();
void destroyStack(Stack* p);
Boolean pushElement(Stack* p, DataType value);
Boolean popElement(Stack* p, DataType* exit);
Boolean topElement(Stack* p, DataType* exit);
void print(Stack* p);
int getSize(Stack* p);
Stack* cloneStack(Stack* p);
void revertStack(Stack* p);
Boolean pushAllElements(Stack* p, DataType* vector, int size);

Stack* createStack(){
  
  Stack* p = (Stack*) malloc(sizeof(Stack));
  p->size = 0;
  return p;
}

void destroyStack(Stack* p){
  Node* temp = p->top;
  Node* aux;
    for(int i = 0; i < p->size; i++){
      aux = temp;
      temp = temp->next;
      free(aux);
    }
  free(p);
}

Boolean pushElement(Stack* p, DataType value){
  
  if(p == NULL) return FALSE;
  
  Node* node = (Node*) malloc(sizeof(Node));
  node->value = value;
  node->next = p->top;
  p->size++;
  p->top = node;
  return TRUE;
}

Boolean popElement(Stack* p, DataType* exit){
  
  if(p == NULL || p->top == NULL) return FALSE;

  *exit = p->top->value;
  Node* aux = p->top;
  p->top = aux->next;
  p->size--; 
  free(aux);
  return TRUE;
}

void print(Stack* p){
  
  Node* aux = p->top;
  for(int i = 0; i < p->size; i++){
    printf("%d -> ", aux->value);
    aux = aux->next;
  }
  free(aux);
  printf("NULL\n");
}

Boolean topElement(Stack* p, DataType* exit){
  
  if (p == NULL || p->top == NULL) return FALSE;

  *exit = p->top->value;
  return TRUE; 
}

int getSize(Stack* p){
  return p->size;
}

Stack* cloneStack(Stack* p){
  
  Stack* clone = (Stack*) malloc(sizeof(Stack));
  Node* caminho = p->top;
  Node* temp;
  for(int i = 0; i < p->size; i++){
    Node* value = (Node*) malloc(sizeof(Node));
    value->value = caminho->value;
      
    if(i == 0) clone->top = value;
    else temp->next = value;
      
    temp = value;
    caminho = caminho->next;
  }
  return clone;
}

void revertStack(Stack* p){
  
  Stack* p1 = createStack();
  Node* aux = p->top;
  while(aux != NULL){
    pushElement(p1,aux->value);
    aux = aux->next;
  }
  p1->size = p->size;
  p->top = p1->top;
}

Boolean pushAllElements(Stack* p, DataType* vetor, int size){

  if (p == NULL) return FALSE;

  for(int i = 0; i < size; i++){
    int aux = vetor[i];
    pushElement(p, aux);
    p->size++;
  }
  return TRUE;
}