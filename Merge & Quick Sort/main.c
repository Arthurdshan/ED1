#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge_sort.h"
#include "quick_sort.h"
#include "aux_functions.h"

#define N 10000
#define MAX_VALUE N * 100
#define SEED 0

int main() {

  clock_t time;
  
  int* v = ordered_vector(N, MAX_VALUE);

  //merge sort

  time = clock();
  merge_sort(v, 0, N);
  time = clock() - time;
  printf("Merge sort\n");  
  printf("Execution time was: %f seconds\n\n",((float)time)/CLOCKS_PER_SEC);

  //quick sort

  time = clock();
  quick_sort(v, 0, N);
  time = clock() - time;
  printf("quick sort\n");  
  printf("Execution time was: %f seconds\n\n",((float)time)/CLOCKS_PER_SEC);
  
  free(v);
  v = NULL;

  return 0;
}