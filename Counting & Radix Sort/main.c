#include <stdio.h>
#include <time.h>
#include "radix_header.h"
#include "vector.h"
#include "main_data.h"

int main(){
  
  printf("%d elements\n", N);
  
  int* vector = random_vector(N, MAX, SEED);

  #if DEBUG 
  printf("printing unordered vector\n");
  printVector(vector, N);
  #endif
  
  t = clock();
  radix_sort(vector, N, 10);
  t = clock() - t;
  printf("decimal execution time(ms): %f\n", ((float)t/(CLOCKS_PER_SEC/1000)));
  
  #if DEBUG 
  printf("printando ordered vector\n");
  printVector(vector, N);
  #endif
  
  printf("verifying if the vector is sorted.. ");
  if(verify_sorted_vector(vector, N)) printf("it is!\n");
  else printf("its not!\n");

  vector = random_vector(N, MAX, SEED);
  
  #if DEBUG 
  printf("printing unordered vector\n");
  printVector(vector, N);
  #endif
  
  t = clock();
  radix_sort(vector, N, 2);
  t = clock() - t;
  printf("binary execution time(ms): %f\n", ((float)t/(CLOCKS_PER_SEC/1000)));
  
  #if DEBUG 
  printf("printando ordered vector\n");
  printVector(vector, N);
  #endif
  
  printf("verifying if the vector is sorted.. ");
  if(verify_sorted_vector(vector, N)) printf("it is!\n");
  else printf("its not!\n");
  
  return 0;

};