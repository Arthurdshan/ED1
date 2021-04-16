#include "header.h"

void insertion_sort(int *v, int n, int *insertion_comparisons){
  int i, aux, j;
  for(i = 1; i < n; i++) {
    aux = v[i];
    j = i - 1;
    while(j >= 0 && v[j] > aux) {
      *insertion_comparisons += 1;
      v[j + 1] = v[j];
      j = j - 1;
    }
    v[j + 1] = aux;
  }
}
