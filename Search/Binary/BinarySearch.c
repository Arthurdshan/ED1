#include "BinarySearch.h"

int binary_search(int* vector, int left, int right, int key){
    int middle;
    if(left <= right){
        middle = (left + right) / 2;
        if(vector[middle] == key) return middle;
        else{
            if(key > vector[middle]) return binary_search(vector, middle + 1, right, key);
            else return binary_search(vector, left, middle -1, key); 
        }
    }
    return -1;
}