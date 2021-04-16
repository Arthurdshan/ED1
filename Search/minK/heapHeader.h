#pragma once

int left(int i);
int right(int i);
int root(int i);
void heap_sort_min(int* v, int size);
void min_heapify(int* v, int i, int size);
void build_min_heap(int* v, int size);