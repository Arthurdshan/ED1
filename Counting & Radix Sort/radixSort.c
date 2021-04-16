#include <stdlib.h>
#include <string.h>

#include "radixHeader.h"

int max_radix(int *vector, int size){
  int max = vector[0];
  for(int i = 1; i < size; i++)
    if(vector[i] > max) 
      max = vector[i];
  return max;
}

void counting_sort_b(int *vector, int size, int div, int base, int *temp){
  int acumulated = 0;
  int *c = (int*) calloc(base, sizeof(int));

  #define DIGIT_BIN(x) (x >> div) & 1
  
  for(int i = 0; i < size; i++) c[DIGIT_BIN(vector[i])]++;

  for(int i = 0; i < base; i++){
    int aux = c[i]; 
    c[i] = acumulated; 
    acumulated += aux;
  }
  for(int i = 0; i < size; i++)
    temp[c[DIGIT_BIN(vector[i])]++] = vector[i];

  memcpy(vector, temp, size * sizeof(int));
  free(c);
}

void counting_sort_d(int* vector, int size, int div, int base, int *temp){
  int acumulated = 0;
  int* c = calloc(base, sizeof(int));

  #define DIGIT(x) (x / div) % base 

  for(int i = 0; i < size; i++) c[DIGIT(vector[i])]++;
  for(int i = 0; i < base; i++){
    int aux = c[i];
    c[i] = acumulated;
    acumulated += aux; 
  }
  for(int i = 0; i < size; i++)
    temp[c[DIGIT(vector[i])]++] = vector[i];
  
  memcpy(vector, temp, sizeof(int) * size);
}

void radix_sort(int* vector, int size, int base){
  int div = 1;
  int pos = 0;
  int largestElement = max_radix(vector, size);
  int* temp = malloc(size * sizeof(int));

  if(base == 2){
    while (largestElement > 0) {
      counting_sort_b(vector, size, pos, base, temp);
      pos++;
      largestElement /= 2;
    }
  }
  
  else{
    while(largestElement > 0){
      counting_sort_d(vector, size, div, base, temp);
      div *= 10;
      largestElement /= 10;
    }
  }
  free(temp);
}


