#include "aux_functions.h"

int left(int i){
  return 2 * i + 1;
};

int right(int i){
  return left(i) + 1;
};

int root(int i){
  return (i - 1) / 2;
}

void switch_elements(int *array, int position, int new_position){
  int aux = array[position];
  array[position] = array[new_position];
  array[new_position] = aux;
};