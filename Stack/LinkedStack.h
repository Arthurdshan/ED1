#pragma once 

#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{FALSE, TRUE} Boolean;
typedef int DataType;

typedef struct node{
	DataType data;
	struct node *next;
}Node;

typedef struct {
	Node *top;
	int size;
}Stack;

Stack* createStack();
void destroyStack(Stack* s);
Boolean pushElement(Stack* s, DataType data);
Boolean popElement(Stack* s, DataType* exit);
Boolean topElement(Stack* s, DataType* exit);
void print(Stack* s);
int getSize(Stack* s);
Stack* cloneStack(Stack* s);
void revertStack(Stack* s);
Boolean pushAllElements(Stack* s, DataType* vector, int size);

Stack* createStack(){
  
  Stack* s = (Stack*) malloc(sizeof(Stack));
  s->size = 0;
  return s;
}

void destroyStack(Stack* s){
  Node* temp = s->top;
  Node* aux;
    for(int i = 0; i < s->size; i++){
      aux = temp;
      temp = temp->next;
      free(aux);
    }
  free(s);
}

Boolean pushElement(Stack* s, DataType data){
  
  if(s == NULL) return FALSE;
  
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->next = s->top;
  s->size++;
  s->top = node;
  return TRUE;
}

Boolean popElement(Stack* s, DataType* exit){
  
  if(s == NULL || s->top == NULL) return FALSE;

  *exit = s->top->data;
  Node* aux = s->top;
  s->top = aux->next;
  s->size--; 
  free(aux);
  return TRUE;
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

Boolean topElement(Stack* s, DataType* exit){
  
  if (s == NULL || s->top == NULL) return FALSE;

  *exit = s->top->data;
  return TRUE; 
}

int getSize(Stack* s){
  return s->size;
}

Stack* cloneStack(Stack* s){
  
  Stack* clone = (Stack*) malloc(sizeof(Stack));
  Node* caminho = s->top;
  Node* temp;
  for(int i = 0; i < s->size; i++){
    Node* data = (Node*) malloc(sizeof(Node));
    data->data = caminho->data;
      
    if(i == 0) clone->top = data;
    else temp->next = data;
      
    temp = data;
    caminho = caminho->next;
  }
  return clone;
}

void revertStack(Stack* s){
  
  Stack* p1 = createStack();
  Node* aux = s->top;
  while(aux != NULL){
    pushElement(p1,aux->data);
    aux = aux->next;
  }
  p1->size = s->size;
  s->top = p1->top;
}

/**
 * Gets a stack, a vector, and push all the elements from the vector to the stack.
 * s = stack
 * vetor = vector
 * size = vector size
*/
Boolean pushAllElements(Stack* s, DataType* vetor, int size){

  if (s == NULL) return FALSE;

  for(int i = 0; i < size; i++){
    int aux = vetor[i];
    pushElement(s, aux);
    s->size++;
  }
  return TRUE;
}