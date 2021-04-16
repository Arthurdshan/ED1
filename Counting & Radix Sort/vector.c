#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int *random_vector(int size, int max, int seed){
  int* newVector = (int*) malloc(size * sizeof(int));
  srand(seed);
  for(int i = 0; i < size; i++) newVector[i] = rand() % (max + 1);
  return newVector;
}

void print_vector(int *vector, int size){  
  printf("[");
  for(int i = 0; i < size; i++){
    printf("%d", vector[i]);
    printf("%s", i == size - 1 ? "]\n" : ", ");
  }
};

bool verify_sorted_vector(int *vector, int size){
  for(int i = 0; i < size; i++){
    if(vector[i] <= vector[i + 1]) break;
    else {printf("%d, %d", vector[i], vector[i + 1]);
    return false;
    }
  }
  return true;
}