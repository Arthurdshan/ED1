#include "heapHeader.h"
#include "auxiliaryFunctions.h"

int left(int i){
  return 2 * i + 1;
};

int right(int i){
  return left(i) + 1;
};

int root(int i){
  return (i - 1) / 2;
}

void min_heapify(int* v, int i, int size){
    int smallest = i;
    int leftElement = left(i);
    int rightElement = right(i);
    if((leftElement < size) && (v[leftElement] < v[i])) 
        smallest = leftElement;
    if((rightElement < size) && (v[rightElement] < v[smallest])) 
        smallest = rightElement;
    if(smallest != i){
        switch_elements(v, i, smallest);
        min_heapify(v, smallest, size);
    }   
};

void build_min_heap(int* v, int size) {
  for(int i = size/2; i >= 0; i--) min_heapify(v, i, size);
}
