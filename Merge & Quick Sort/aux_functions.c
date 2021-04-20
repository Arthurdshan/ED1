#include <stdio.h>
#include "aux_functions.h"
#include <stdlib.h>

/* returns a shuffled array based on seed parameter
and srand func */
int *random_vector(int size, int max, int seed) {

  int *v = (int *) calloc(size, sizeof(int));
  srand(seed);
  for(int i = 0; i < size; i++) v[i] = rand() % max;
  
  return v;
};

//returns a sorted array from 0 to max size
int *ordered_vector(int size, int max){

  int* v = (int*) calloc(size, sizeof(int));
  for(int i = 0; i < size; i++) v[i] = i;
  return v;
}

void print_vector(int *vector, int length){  
  printf("[");
  for(int i = 0; i < length; i++){
      printf("%d", vector[i]);
      printf("%s", i == length - 1 ? "]\n" : ", ");
  }
};

int max_value(int *vector, int initial_position, int final_position){
  int biggerElementIndex = final_position;
  int aux = vector[final_position];
  for(int i=final_position; i>initial_position; i--){
    if(vector[i - 1] > aux){
      aux = vector[i - 1];
      biggerElementIndex = i - 1;
    }
  }
  return biggerElementIndex;
};

void switch_elements(int *vector, int position, int next_position){
  int aux = vector[position];
  vector[position] = vector[next_position];
  vector[next_position] = aux;
};
