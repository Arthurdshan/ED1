#include "StaticStack.h"

Stack* create_stack(){
  Stack* p1= (Stack*) malloc(sizeof(Stack));
  p1->vector = (int*) calloc(N, sizeof(int)); 
  p1->size = 0;
  p1->length = N;
  return p1;
}

void destroy_stack(Stack* s){
  free(s->vector);
  free(s);
}

Boolean push_element(Stack* s, int data){
  if(s == NULL) return false;
  if(s->size == s->length) return false;
  s->vector[s->size] = data;
  s->size++;
  return true;
}

Boolean pop_element(Stack* s, int* saida){
  if(s == NULL || s->size == 0) return false;

  *saida = s->vector[s->size - 1];
  s->size--;
  return true;
  }

Boolean top_element(Stack* s, int* saida){
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

Stack* clone_stack(Stack* s){
  Stack* p1= create_stack();
  p1->length = s->length;
  p1->size = s->size;
  for(int i = 0; i < s->size; i++){
    p1->vector[i] = s->vector[i];
  }
  return p1;
}

void revert_stack(Stack* s){
  
  if(s == NULL) return;

  int* inverso = (int*) calloc(s->length, sizeof(int));
  for(int i = s->size - 1, j = 0; i >= 0; i--, j++){
    inverso[j] = s->vector[i];
  }
  free(s->vector);
  s->vector = inverso;
}

Boolean push_all_elements(Stack* s, int* vector, int lengthvector){
  if (s == NULL|| lengthvector <= 0) return false;

  for(int i = 0; i < lengthvector; i++){
    push_element(s, vector[i]);
  }
  return true;
}
