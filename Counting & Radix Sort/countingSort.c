#include <stdlib.h>
#include <string.h>
#include "countingHeader.h"

int get_max_element(Info *vector, int size){
  int max = vector[0].key;
  for(int i = 1; i < size; i++)
    if(vector[i].key > max) max = vector[i].key;
  return max;
}

void counting_sort(Info *vector, int size){
  int largestElement = get_max_element(vector, size);
  int counter = 0;
  int* key = calloc(size + 1, sizeof(int));
  Info* output = malloc(size * sizeof(Info));

  for(int j = 0; j < size; j++) key[vector[j].key]++;
  for(int i = 0; i <= largestElement; i++){
    int aux = key[i];
    key[i] = counter;
    counter += key[aux]; 
  }
  for(int i = 0; i < size; i++){
    output[key[vector[i].key]] = vector[i];
    key[vector[i].key]++;  
  }
  memcpy(vector, output, sizeof(Info) * size);
  free(key);
  free(output);
}