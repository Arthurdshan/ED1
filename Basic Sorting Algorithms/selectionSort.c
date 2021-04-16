#include "header.h"

void selection_sort(int *vector, int quantity, int *selection_comparisons){
  int aux;
  for(int i = quantity - 1; i > 0; i--){ 
    aux = max_value(vector, 0, i, selection_comparisons);
    switch_elements(vector, aux, i); 
  }
};
