#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

#define N 10000
#define MAX_VALUE 1000
#define SEED 0

int main() {

  int comparisons = 0;
  clock_t time;

  //selection sort
  int* v1 = random_vector(N, MAX_VALUE, SEED);
  time = clock();
  selection_sort(v1, N, &comparisons);
  time = clock() - time;
  printf("Selection sort comparisons: %d\n", comparisons);
  printf("Execution time was: %f seconds\n\n",((float)time)/CLOCKS_PER_SEC);

  //insertion sort
  comparisons = 0;
  time = 0;
  int* v2 = random_vector(N, MAX_VALUE, SEED);

  time = clock();
  insertion_sort(v2, N, &comparisons);
  time = clock() - time;

  printf("Insertion sort comparisons: %d\n", comparisons);
  printf("Execution time was: %f seconds\n\n",((float)time)/CLOCKS_PER_SEC);

  //bubble sort
  comparisons = 0;
  time = 0;
  int* v3 = random_vector(N, MAX_VALUE, SEED);

  time = clock();
  bubble_sort(v3, N, &comparisons);
  time = clock() - time;  
  
  printf("Bubble sort comparisons: %d\n", comparisons);
  printf("Execution time was: %f seconds\n\n",((float)time)/CLOCKS_PER_SEC);
  
  free(v1);
  free(v2);
  free(v3);
  v1 = NULL;
  v2 = NULL;
  v3 = NULL;
  
  return 0;
}