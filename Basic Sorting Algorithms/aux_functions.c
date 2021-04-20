#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int* random_vector(int size, int max, int seed) {

  int* v = (int*) calloc(size, sizeof(int));
  
  srand(seed);

  for(int i = 0; i < size; i++) v[i] = rand() % max;
  
  return v;
};

void print_vector(int *vector, int length){  
  printf("[");
  for(int i = 0; i < length; i++){
    printf("%d", vector[i]);
    printf("%s", i == length - 1 ? "]\n" : ", ");
  }
};

int max_value(int *vector, int initialPosition, int finalPosition, int *comparisons){
  int biggerElementIndex = finalPosition;
  int aux = vector[finalPosition];
  for(int i=finalPosition; i>initialPosition; i--){
    if(vector[i - 1] > aux){
      aux = vector[i - 1];
      biggerElementIndex = i - 1;
    }
  *comparisons += 1;
  }
  return biggerElementIndex;
};

void switch_elements(int *vector, int position, int next_position){
  int aux = vector[position];
  vector[position] = vector[next_position];
  vector[next_position] = aux;
};
