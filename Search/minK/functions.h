#pragma once

/**
 * Functions that searches for the k-th smaller
 * key from the vector.
 * V = vector
 * n = size
 * e = left 
 * d = right
 * k = key element
*/
int SelectionMinK(int *v, int n, int k);
int HeapMinK(int *v, int n, int k);
int QuickMinK(int *v, int e, int d, int k);