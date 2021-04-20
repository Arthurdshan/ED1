#include "heap_sort.h"
#include "aux_functions.h"

//Sort function based on max heapify
void heap_sort_max(int *array, int size){
    build_max_heap(array, size);
    for(int i = size - 1; i > 0; i--){
        switch_elements(array, 0, i);
        max_heapify(array, 0, i);
    }
};

//Sort function based on min heapify
void heap_sort_min(int *array, int size){
 build_min_heap(array, size);
  for(int i = size - 1 ; i > 0; i--){
    switch_elements(array, 0, i);
    min_heapify(array, 0, i);
  }
};

//Max heap functions 
void max_heapify(int *array, int i, int size){
    int largest = i;
    int left_element = left(i);
    int right_element = right(i);
    
    if((left_element < size) && (array[left_element] > array[i])) largest = left_element;
    if((right_element < size) && (array[right_element] > array[largest])) largest = right_element;
    if(largest != i){
        switch_elements(array, i, largest);
        max_heapify(array, largest, size);
    }
};

void build_max_heap(int *array, int size){
    for(int i = size/2; i >= 0; i--) max_heapify(array, i, size);
};

//Min heap functions 
void min_heapify(int *array, int i, int size){
    int smallest = i;
    int left_element = left(i);
    int right_element = right(i);
    if((left_element < size) && (array[left_element] < array[i])) smallest = left_element;
    if((right_element < size) && (array[right_element] < array[smallest])) smallest = right_element;
    if(smallest != i){
        switch_elements(array, i, smallest);
        min_heapify(array, smallest, size);
    }   
};

void build_min_heap(int *array, int size) {
  for(int i = size/2; i >= 0; i--) min_heapify(array, i, size);
}
