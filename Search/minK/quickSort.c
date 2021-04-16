#include "auxiliaryFunctions.h"
#include "quickSort.h"

int partition(int* vector, int p, int r){
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
