#include <stdio.h>
#include "functions.h"
#include "auxiliaryFunctions.h"
#include "priorityQueue.h"
#include "heapHeader.h"
#include "quickSort.h"

int SelectionMinK(int *v, int n, int k){
    if(n < k) return v[max_value(v, n)];        

    int aux, position;

    for(int i = 0; i < k; i++){ 
        aux = min_value(v, i, n - 1);
        switch_elements(v, i, aux); 
        position = i;
    }
    return v[position];   
}

int HeapMinK(int *v, int n, int k){
    if(n < k) return v[max_value(v, n)];
    
    build_min_heap(v, n);

    for(int i = n - 1; i > n - k; i--){
        switch_elements(v, 0, i);
        min_heapify(v, 0, i);
    }
    return v[0];
}

int QuickMinK(int *v, int e, int d, int k){
    int pivot, x;
    if(k > d) return v[max_value(v, d)];    
    if(e <= d){
        pivot = partition(v, e, d);
        if(pivot == k - 1) return v[pivot];
        else if(pivot > k - 1) x = QuickMinK(v, e, pivot - 1, k);
        else x =QuickMinK(v, pivot, d, k);
    }
    return x;
}