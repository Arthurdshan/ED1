#include "LinearSearch.h"

int linear_search(int* vector, int size, int key){
    for(int i = 0; i < size; i++)
        if(vector[i] == key)
            return i;
    return -1;
}