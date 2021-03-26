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
void destroyStack(Stack* s);
Boolean pushElement(Stack* s, DataType value);
Boolean popElement(Stack* s, DataType* saida);
Boolean topElement(Stack* s, DataType* saida);
void print(Stack* s);
int getSize(Stack* s);
Stack* cloneStack(Stack* s);
void revertStack(Stack* s);
Boolean pushAllElements(Stack* s, DataType* vector, int lengthvector);

Stack* createStack(){
  Stack* p1= (Stack*) malloc(sizeof(Stack));
  p1->vector = (DataType*) calloc(N, sizeof(DataType)); 
  p1->size = 0;
  p1->length = N;
  return p1;
}

void destroyStack(Stack* s){
  free(s->vector);
  free(s);
}

Boolean pushElement(Stack* s, DataType value){
  if(s == NULL) return FALSE;
  if(s->size == s->length) return FALSE;
  s->vector[s->size] = value;
  s->size++;
  return TRUE;
}

Boolean popElement(Stack* s, DataType* saida){
  if(s == NULL || s->size == 0) return FALSE;

  *saida = s->vector[s->size - 1];
  s->size--;
  return TRUE;
  }

Boolean topElement(Stack* s, DataType* saida){
  if (s == NULL) return FALSE;

  saida = &s->vector[s->size];
  return TRUE; 
}

void print(Stack *s){
  if (s == NULL) return;
  
  for(int i = 0; i < 5; i++){
    if(i == s->size-1) printf("%d\n", s->vector[i]);
    else printf("%d -> ", s->vector[i]);
  }
}

int getSize(Stack* s){
  return s->size;
}

Stack* cloneStack(Stack* s){
  Stack* p1= createStack();
  p1->length = s->length;
  p1->size = s->size;
  for(int i = 0; i < s->size; i++){
    p1->vector[i] = s->vector[i];
  }
  return p1;
}

void revertStack(Stack* s){
  
  if(s == NULL) return;

  DataType* inverso = (DataType*) calloc(s->length, sizeof(DataType));
  for(int i = s->size - 1, j = 0; i >= 0; i--, j++){
    inverso[j] = s->vector[i];
  }
  free(s->vector);
  s->vector = inverso;
}

Boolean pushAllElements(Stack* s, DataType* vector, int lengthvector){
  if (s == NULL|| lengthvector <= 0) return FALSE;

  for(int i = 0; i < lengthvector; i++){
    pushElement(s, vector[i]);
  }
  return TRUE;
}
