#pragma once

typedef enum { false, true } bool;

int *random_vector(int size, int max, int seed);
void print_vector(int* vector, int size);
bool verify_sorted_vector(int* vector, int size);