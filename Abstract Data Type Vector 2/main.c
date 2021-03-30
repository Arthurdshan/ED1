#include<stdio.h>
#include<stdlib.h>
#include "ADT.h"

void teste1(){
  printf("!!!!!!!!!!Part 1!!!!!!!!!\n\n");
  Vector* v1 = vet_new();

  Product* p1 = create_product(10, "Sabonete", 1.99);
  Product* p2 = create_product(20, "teclado", 38.60);
  Product* p3 = create_product(30, "mouse", 34.64);
  Product* p4 = create_product(40, "oculos", 35.64);
  Product* p5 = create_product(50, "cadeira", 121.64);
  Product* p6 = create_product(60, "pirulito", 13.64);
  Product* p7 = create_product(70, "caderno", 8.64);

  vet_insertEnd(v1, *p1);
  vet_insertEnd(v1, *p2);
  vet_insertEnd(v1, *p3);
  vet_insertEnd(v1, *p4);
  vet_insertEnd(v1, *p5);
  vet_insertEnd(v1, *p6);
  vet_insertEnd(v1, *p7);
  vet_print(v1);

  printf("inserindo caderno na posição 2!\n");
  vet_insert(v1, *p7, 2);
  vet_print(v1);
  
  printf("inserindo o produto 5 na posição final!\n");
  vet_substitute(v1, -1, *p5);
  vet_print(v1);

  printf("removendo o elemento na posição -2!\n");
  DataType* ptr;
  vet_removePosition(v1, -2, ptr);
  vet_print(v1);
  
  printf("removendo o produto 2!\n");
  int pos = vet_removeElement(v1, *p2);
  vet_print(v1);
  
  printf("%d elementos no vetor!\n\n", vet_size(v1));
  
  DataType* exit;
  vet_element(v1, 3, exit);

  if(vet_position(v1, *p1) == -1) printf("posição não encontrada!\n");
  else printf("elemento p1 encontrado na posição %d\n\n", vet_position(v1, *p1));

  printf("vetor passado para a string!\n");
  char vetString[100];
  vet_toString(v1, vetString);
  printf("\n%s\n\n", vetString);
  
  vet_free(v1);
  free(p1);
  free(p2);
  free(p3);
  free(p4);
  free(p5);
  free(p6);
  free(p7);
  v1 = NULL;
  p1 = NULL;
  p2 = NULL;
  p3 = NULL;
  p4 = NULL;
  p5 = NULL;
  p6 = NULL;
  p7 = NULL;
}

void teste2(){
  printf("!!!!!!!!!!Part 2!!!!!!!!!\n\n");
  Vector* v2 = vet_new();

  Product* p1 = create_product(10, "Sabonete", 1.99);
  Product* p2 = create_product(20, "teclado", 38.60);
  Product* p3 = create_product(30, "mouse", 34.64);
  Product* p4 = create_product(40, "oculos", 35.64);
  Product* p5 = create_product(50, "cadeira", 121.64);
  Product* p6 = create_product(60, "pirulito", 13.64);
  Product* p7 = create_product(70, "caderno", 8.64);

  vet_insertEnd(v2, *p5);
  vet_insertEnd(v2, *p1);
  vet_insertEnd(v2, *p6);
  vet_insertEnd(v2, *p2);
  vet_insertEnd(v2, *p3);
  vet_insertEnd(v2, *p7);
  vet_insertEnd(v2, *p4);

  Vector* v3 = vet_clone(v2);
  Vector* v4 = vet_clone(v2);
  Vector* v5 = vet_clone(v2);

  printf("Bubble sort\n");
  vet_bubblesort(v3);
  vet_print(v3);
  printf("Insertion sort\n");
  vet_insertionsort(v4);
  vet_print(v4);
  printf("Selection sort\n");
  vet_selectionsort(v5);
  vet_print(v5);
  
  if(vet_binarysearch(v3, *p3) == -1) printf("position not found!\n");
  else printf("found on position %d\n\n", vet_binarysearch(v3, *p3));
}

void teste3(){
  printf("!!!!!!!!!!Part 3!!!!!!!!!\n\n");
  char nomeArquivo1[] = "lista_produtos.txt";
  Vector* v2 = vet_import(nomeArquivo1);
  vet_print(v2);
  char nomeArquivo2[] = "lista_produtos1.txt";
  if(vet_export(v2, nomeArquivo2)) printf("Valores passados com sucesso para o arquivo\n\n");
  else printf("Valores não importados\n\n");
  
  vet_free(v2);
  v2 = NULL;
}

int main(){

  teste3();
}