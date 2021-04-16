#pragma once

int *random_vector(int size, int max, int seed);
void print_vector(int *vector, int length);
int max_value(int *vector, int initial_position, int finalPosition, int *comparisons);
void switch_elements(int *vector, int position, int nextPosition);
void selection_sort(int *vector, int quantity, int *selection_comparisons);
void insertion_sort(int *vector, int quantity, int *comparisons);
void bubble_sort(int *vector, int quantity, int *bubble_comparisons);
