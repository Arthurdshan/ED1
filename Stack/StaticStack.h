#pragma once 

#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef enum boolean{FALSE, TRUE} Boolean;
typedef int DataType;

typedef struct {
	DataType* vector;
	int length;
	int size;
}Stack;

Stack* createStack();
void destroyStack(Stack* p);
Boolean pushElement(Stack* p, DataType value);
Boolean popElement(Stack* p, DataType* saida);
Boolean topElement(Stack* p, DataType* saida);
void print(Stack* p);
int getSize(Stack* p);
Stack* cloneStack(Stack* p);
void revertStack(Stack* p);
Boolean pushAllElements(Stack* p, DataType* vector, int lengthvector);

Stack* createStack(){
  Stack* p1= (Stack*) malloc(sizeof(Stack));
  p1->vector = (DataType*) calloc(N, sizeof(DataType)); 
  p1->size = 0;
  p1->length = N;
  return p1;
}

void destroyStack(Stack* p){
  free(p->vector);
  free(p);
}

Boolean pushElement(Stack* p, DataType value){
  if(p == NULL) return FALSE;
  if(p->size == p->length) return FALSE;
  p->vector[p->size] = value;
  p->size++;
  return TRUE;
}

Boolean popElement(Stack* p, DataType* saida){
  if(p == NULL || p->size == 0) return FALSE;

  *saida = p->vector[p->size - 1];
  p->size--;
  return TRUE;
  }

Boolean topElement(Stack* p, DataType* saida){
  if (p == NULL) return FALSE;

  saida = &p->vector[p->size];
  return TRUE; 
}

void print(Stack *p){
  if (p == NULL) return;
  
  for(int i = 0; i < 5; i++){
    if(i == p->size-1) printf("%d\n", p->vector[i]);
    else printf("%d -> ", p->vector[i]);
  }
}

int getSize(Stack* p){
  return p->size;
}

Stack* cloneStack(Stack* p){
  Stack* p1= createStack();
  p1->length = p->length;
  p1->size = p->size;
  for(int i = 0; i < p->size; i++){
    p1->vector[i] = p->vector[i];
  }
  return p1;
}

void revertStack(Stack* p){
  
  if(p == NULL) return;

  DataType* inverso = (DataType*) calloc(p->length, sizeof(DataType));
  for(int i = p->size - 1, j = 0; i >= 0; i--, j++){
    inverso[j] = p->vector[i];
  }
  free(p->vector);
  p->vector = inverso;
}

Boolean pushAllElements(Stack* p, DataType* vector, int lengthvector){
  if (p == NULL|| lengthvector <= 0) return FALSE;

  for(int i = 0; i < lengthvector; i++){
    pushElement(p, vector[i]);
  }
  return TRUE;
}
