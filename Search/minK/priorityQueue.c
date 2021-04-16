#include "auxiliaryFunctions.h"
#include "heapHeader.h"

int remove_min_element(int* priorityQueue, int size){
    int newSize = size - 1;
    switch_elements(priorityQueue, 0, newSize);
    min_heapify(priorityQueue, 0, newSize);
    return newSize;
}