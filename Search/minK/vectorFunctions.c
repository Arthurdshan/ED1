#include <stdio.h>
#include <stdlib.h>
#include "vectorFunctions.h"
#include "auxiliaryFunctions.h"

void print_vector(int* vector, int length){  
  printf("[");
  for(int i = 0; i < length; i++){
    printf("%d", vector[i]);
    printf("%s", i == length - 1 ? "]\n" : ", ");
  }
}

int* random_vector_unique_elems(int n, int seed){
  int* vector = (int*) malloc(n * sizeof(int));
  
  srand(seed);

  for(int i = 0; i < n; i++) vector[i] = i + 1;
  shuffle(vector, 0, n);
  return vector;
}

void shuffle(int *v, int start, int end){
  int j = 0;
  for(int i = end - 1; i > start; i--){
    j = (rand() % (i + 1));
    j = j <= start ? start + 1 : j;
    switch_elements(v, i, j);
  }
}
