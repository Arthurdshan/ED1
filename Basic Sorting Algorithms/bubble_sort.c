#include "header.h"

void bubble_sort(int *vector, int quantity, int *bubble_comparisons){
  int i, j;
  for(j = quantity - 1; j > 0; j--){
    for(i=0; i < j; i++){
      *bubble_comparisons += 1;  
      if(vector[i] > vector[i+1])  switch_elements(vector, i, i+1);
    }
  }
};