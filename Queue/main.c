#include<stdio.h>
#include<stdlib.h>
//#include "FilaCircular.h"
#include "FilaEncadeada.h"

int main(){
	// Desenvolva os testes para verificar se a função implementada 
  //está funcionando como esperado
  int removido, primeiro;
  int t = 3;
  TipoElemento v[3] = {1,2,3};
  Fila* f = fila_criar();     
  printf("fila criada.\n");
  fila_imprimir(f);          
  fila_inserir(f, 1);                       
  fila_inserir(f, 2);                       
  fila_inserir(f, 3);                        
  fila_inserir(f, 4); 
  fila_imprimir(f);
  fila_remover(f, &removido);              
  fila_imprimir(f);
  printf("Valor removido: %d\n", removido);

  fila_primeiro(f, &primeiro);
  printf("primeiro valor: %d\n", primeiro); 
  printf("clone da fila:\n"); 
  Fila* fc = fila_clone(f);
  fila_imprimir(fc);
  printf("fila clone invertida:\n");
  fila_inverter(fc);
  fila_imprimir(fc);
  printf("inserindo vetor na fila:\n");
  fila_inserirTodos(f, v, t);
  fila_imprimir(f);
  printf("%d elementos na fila.\n",fila_tamanho(f));
  printf("%d elementos na fila clone.\n",fila_tamanho(fc));
  fila_destruir(f);
  fila_destruir(fc);
}