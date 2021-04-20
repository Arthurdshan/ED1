#include "quick_sort.h"
#include "aux_functions.h"

int partition(int *vector, int p, int r){
  int x;
  int i, j;
  i = p - 1;
  x = vector[r];
  for(j = p; j < r; j++){
    if(vector[j] <= x){
      i++;
      switch_elements(vector, i, j);
    }
  }
  switch_elements(vector, i + 1, r);
  return i + 1;
}

void quick_sort(int *vector, int left, int right){
  int pivot;
  if(left < right){
    pivot = partition(vector, left, right);
    quick_sort(vector, left, pivot - 1);
    quick_sort(vector, pivot + 1, right);
  }
}