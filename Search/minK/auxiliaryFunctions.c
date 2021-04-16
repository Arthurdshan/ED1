#include <stdio.h>
#include "auxiliaryFunctions.h"

int max_value(int *vector, int size){
  int largest = 0;
  for(int i = 1; i < size; i++){
    if(vector[largest] < vector[i]) largest = i;
  }
  return largest;
}

int min_value(int *vector, int initialPosition, int finalPosition){
  int min = initialPosition;
  for(int i = initialPosition + 1; i <= finalPosition; i++)
    if(vector[i] < vector[min]) min = i;
  return min;
}

void switch_elements(int* vector, int position, int nextPosition){
  int aux = vector[position];
  vector[position] = vector[nextPosition];
  vector[nextPosition] = aux;
}