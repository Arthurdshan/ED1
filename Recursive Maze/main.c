#include <stdio.h>
#include "labyrinth.h"

int main(){

  int MATRIX[T][T];

  char labyrinth[] = "lab.txt";
  load_matrix(labyrinth, MATRIX);
  
  print_matrix(MATRIX);
  
  printf("\nposition:\n");
  if(search(MATRIX, 0, 0)) printf("\n\nexit found!\n\n");
  else printf("\n\nthere's no exit!\n\n");

  return 0;
}
