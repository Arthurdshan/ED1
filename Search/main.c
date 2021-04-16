#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minK/auxiliaryFunctions.h"
#include "minK/vectorFunctions.h"
#include "minK/functions.h"

#define SEED 42
#define K 1
// #define K n/3
// #define K n/2
// #define K n

void test(){
    
    int n = 1000;
    
    clock_t t;

    printf("\n///////////////////////////////////////////////////\n");
    printf("\nvalue of K: %d\n", K);
    printf("\n///////////////////////////////////////////////////\n");
        
    int i = 0;
    
    while(i < 5){
    
        printf("\n///////////////////////////////////////////////////\n");
        printf("\nvalue of N: %d\n", n);
        printf("\n///////////////////////////////////////////////////\n\n");
    
        int* vector = random_vector_unique_elems(n, SEED);

        int kth;

        if(K <= 10000) {
            t = clock();
            kth = SelectionMinK(vector, n, K);
            t = clock() - t;
            printf("K-th: %d\t selection execution time: %f\n", kth, ((float)t/CLOCKS_PER_SEC)*1000);
        }

        free(vector);
        
        vector = random_vector_unique_elems(n, SEED);
        
        t = clock();
        kth = HeapMinK(vector, n, K);
        t = clock() - t;
        printf("K-th: %d\t heap execution time: %f\n", kth, ((float)t/CLOCKS_PER_SEC)*1000);
        
        free(vector);
        
        vector = random_vector_unique_elems(n, SEED);

        t = clock();
        kth = QuickMinK(vector, 0, n - 1, K);
        t = clock() - t;
        printf("K-th: %d\t quick execution time: %f\n", kth, ((float)t/CLOCKS_PER_SEC)*1000);
        
        free(vector);

        switch(i){
            case 2: n *= 5; break;
            case 3: n *= 2; break;
            default: n *= 10; break;
        }
        i++;
    }
}

int main(){

    printf("Time is displayed in miliseconds...\n");
    test(); 

}