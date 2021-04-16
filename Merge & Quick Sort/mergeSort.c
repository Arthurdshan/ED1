#include <stdlib.h>
#include <limits.h>
#include "mergeSort.h"

void merge_sort(int *vector, int left, int right){
  int middle;
  if(left < right){
    middle = ((left + right) / 2);
    merge_sort(vector, left, middle);
    merge_sort(vector, middle+1, right);
    merge(vector, left, middle, right);
  }
};

void merge(int* vector, int initial_position, int middle, int final_position){
  int i, j, k; 
  
  int quantityLeft = middle - initial_position + 1;
  int quantityRight = final_position - middle; 

  int* left = malloc(sizeof(int) * (quantityLeft + 1));
  int* right = malloc(sizeof(int) * (quantityRight + 1));

  for(i=0;i<quantityLeft;i++) left[i] = vector[initial_position + i];
  
  for(j=0;j<quantityRight;j++) right[j] = vector[middle + j + 1]; 
  
  left[quantityLeft] = right[quantityRight] = INT_MAX;

  i = j = 0;

  for(k=initial_position; k <= final_position; k++)
    if(left[i] <= right[j]){
      vector[k] = left[i];
      i++;
    }else{
      vector[k] = right[j];
      j++;
    }
  free(left);
  free(right);
};