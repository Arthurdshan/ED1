#pragma once

int max_radix(int *vector, int size);
void counting_sort_d(int *vector, int size, int div, int base, int *temp);
void counting_sort_b(int *vector, int size, int div, int base, int *temp);
void radix_sort(int *vector, int size, int base);
