#include <stdio.h>

#include "labyrinth.h"

//Get the maze from lab.txt archive
void load_matrix(char* archive, int mat[T][T]){
    
  FILE *arq = fopen(archive, "r");
  
  for(int i = 0; i < T; i++)
    for(int j =0; j < T; j++) fscanf(arq,"%d",&mat[i][j]);
  fclose(arq);
}

void print_matrix(int mat[T][T]){
  printf("[][][][][][][][][][][][]\n");
  for(int i = 0; i < T; i++){
    printf("[]");
      for(int j = 0; j < T; j++){
        if(i == 0 && j == 0) printf("! ");
        else if(mat[i][j] == BLOCK) printf("[]");
        else if(i == 9 && j == 9) printf(" #");
        else printf("  ");
        if (j == 9 && i != 9) printf("[]");
      }
      printf("\n");
  }
  printf("[][][][][][][][][][][]\n");
}

int search(int mat[T][T],int lin,int col){
    
  int aux;
  
  if((lin >= T) || (lin < 0) || (col >= T) || (col < 0)) aux = 0;
  else if(mat[lin][col] == BLOCK) aux = 0;
  else if(lin == 9 && col == 9) aux = 1;
  else{
    mat[lin][col] = 1;
    //make use of recursive functions to walk through the maze
    aux = search(mat,lin-1,col);
    aux |= search(mat,lin+1,col);
    aux |= search(mat,lin,col-1);
    aux |= search(mat,lin,col+1);  
  }
  if(aux == 1) printf("position:[%d, %d]\n", lin, col);

  return aux;
}
