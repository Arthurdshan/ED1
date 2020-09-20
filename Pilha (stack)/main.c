#include<stdio.h>
#include<stdlib.h>
//#include "PilhaContigua.h"
#include "PilhaEncadeada.h"


int main(){
  
  Pilha* p = pilha_criar();

  pilha_empilhar(p, 1);
  pilha_empilhar(p, 2);
  pilha_empilhar(p, 3);
  pilha_empilhar(p, 4);
  pilha_empilhar(p, 5);

  pilha_imprimir(p);

  TipoElemento saida1;
  pilha_desempilhar(p, &saida1);
  pilha_imprimir(p);
  
  TipoElemento saida2;
  pilha_topo(p, &saida2);
  
  TipoElemento tam;
  tam = pilha_tamanho(p);
  
  Pilha* pc = pilha_clone(p);
  printf("clone da pilha\n");
  pilha_imprimir(pc);

  printf("inverso da pilha\n");
  pilha_inverter(pc);
  pilha_imprimir(pc);

  printf("empilhando vários elementos\n");
  int vet[4] = {5,6,7,8};
  pilha_empilharTodos(p, vet, 4);
  pilha_imprimir(p);

  pilha_destruir(p);
  pilha_destruir(pc);
  p = NULL;
  pc = NULL;
}
