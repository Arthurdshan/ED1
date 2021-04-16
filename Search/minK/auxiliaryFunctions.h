#pragma once

int* random_vector_unique_elems(int n, int seed);
void shuffle(int *v, int start, int end);
void switch_elements(int* vector, int position, int nextPosition);
void print_vector(int* vector, int length);
int max_value(int *vector, int size);
int min_value(int *vector, int initialPosition, int finalPosition);