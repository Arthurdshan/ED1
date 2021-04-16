#pragma once

#define T 10
#define EMPTY 0
#define BLOCK 1

void load_matrix(char* archive, int mat[T][T]);
void print_matrix(int mat[T][T]);
int search(int mat[T][T],int lin,int col);

