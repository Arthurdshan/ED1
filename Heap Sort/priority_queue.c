#include <stdlib.h>
#include "priority_queue.h"
#include "aux_functions.h"
#include "heap_sort.h"

int *create_queue(int size) {
    int *queue = (int *) malloc(size * sizeof(int));

    return queue;
};

int get_first_element(int *priority_queue, int size){
    return priority_queue[0];
}

int remove_max_element(int *priority_queue, int size){
    int newSize = size - 1;
    switch_elements(priority_queue, 0, newSize);
    max_heapify(priority_queue, 0, newSize);
    return newSize;
}

int insert_new_element(int *priority_queue, int size, int new_element){
  int newSize = size + 1;
  priority_queue[size] = new_element;

  while(priority_queue[size] > priority_queue[root(size)]){
    switch_elements(priority_queue, size, root(size));
    size = root(size);
  }
  return newSize;
}

int remove_min_element(int *priority_queue, int size) {
    int newSize = size - 1;
    switch_elements(priority_queue, 0, newSize);
    min_heapify(priority_queue, 0, newSize);
    return newSize;
}

int insert_new_min_element(int *priority_queue, int size, int new_element) {
    priority_queue[size] = new_element;

    while(priority_queue[size] < priority_queue[root(size)]) {
        switch_elements(priority_queue, size, root(size));
        size = root(size);
    }
    return size - 1;
}