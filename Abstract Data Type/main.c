#include<stdio.h>
#include<stdlib.h>
#include "ADT.h"

void teste1();
void teste2();
void teste3();
void teste4();

void teste1(){

  printf("!!!!!!!!!!!PARTE 1!!!!!!!!!\n");
  Vetor* v1 = vet_new();
  DataType* exit;
  DataType* ptr;
  char vetString[20];
  
  vet_insertEnd(v1, 1);
  vet_insertEnd(v1, 10);
  vet_insertEnd(v1, 20);
  vet_insertEnd(v1, 30);
  vet_insertEnd(v1, 40);
  vet_print(v1);
  vet_insert(v1, 100, -4);
  vet_print(v1);
  vet_substitute(v1, -1, 2);
  vet_print(v1);
  vet_removePosition(v1, -1, ptr);
  vet_print(v1);
  int pos = vet_removeElement(v1, 30);
  vet_print(v1);
  vet_element(v1, 1, exit);
  int pos1 = vet_position(v1, 10);
  vet_toString(v1, vetString);
  vet_free(v1);
  v1 = NULL;
}

void teste2(){
  printf("!!!!!!!!!!!PARTE 2!!!!!!!!!\n");
  Vetor* v2 = vet_new();
  vet_insertEnd(v2, 40);
  vet_insertEnd(v2, 20);
  vet_insertEnd(v2, 10);
  vet_insertEnd(v2, 30);
  vet_insertEnd(v2, 1);
  vet_print(v2);
  Vetor* clone1 = vet_clone(v2);
  Vetor* clone2 = vet_clone(v2);
  Vetor* clone3 = vet_clone(v2);
  vet_bubblesort(clone1);
  vet_print(clone1);
  vet_selectionsort(clone2);
  vet_print(clone2);
  vet_insertionsort(clone3);
  vet_print(clone3);
  printf("posição %d\n",vet_binarysearch(clone1, 20));


  vet_free(v2);
  vet_free(clone1);
  vet_free(clone2);
  vet_free(clone3);
  v2= NULL;
  clone1 = NULL;
  clone2 = NULL;
  clone3 = NULL;
}

void teste3(){
  printf("!!!!!!!!!!!PARTE 3!!!!!!!!!\n");
  char nomeArquivo1[] = "arquivo_entrada.txt";
  Vetor* v3 = vet_import(nomeArquivo1);
  vet_print(v3);
  char nomeArquivo2[] = "arquivo_entrada1.txt";
  if(vet_export(v3, nomeArquivo2)){
      printf("Valores passados com sucesso para o arquivo\n");
  }
  else printf("Valores não importados\n");
  vet_free(v3);
  v3 = NULL;
}

void teste4(){
  printf("!!!!!!!!!!!PARTE 4!!!!!!!!!\n");
  Vetor* v4 = vet_newrandom(10);
  Vetor* v5 = vet_newupward(10);
  Vetor* v6 = vet_newdownward(10);
  Vetor* v7 = vet_partialupward(10, 50);
  vet_print(v4);
  vet_print(v5);
  vet_print(v6);
  vet_print(v7);


  vet_free(v4);
  v4 = NULL;
  vet_free(v5);
  v5 = NULL;
  vet_free(v6);
  v6 = NULL;
  vet_free(v7);
  v7 = NULL;

}

int main(){

  teste1();
  teste2();
  teste3();
  teste4();

}

