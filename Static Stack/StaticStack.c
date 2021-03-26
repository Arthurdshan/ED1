#include "StaticStack.h"

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

Boolean pushElement(Stack* s, DataType data){
  if(s == NULL) return false;
  if(s->size == s->length) return false;
  s->vector[s->size] = data;
  s->size++;
  return true;
}

Boolean popElement(Stack* s, DataType* saida){
  if(s == NULL || s->size == 0) return false;

  *saida = s->vector[s->size - 1];
  s->size--;
  return true;
  }

Boolean topElement(Stack* s, DataType* saida){
  if (s == NULL) return false;

  saida = &s->vector[s->size];
  return true; 
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
  if (s == NULL|| lengthvector <= 0) return false;

  for(int i = 0; i < lengthvector; i++){
    pushElement(s, vector[i]);
  }
  return true;
}
