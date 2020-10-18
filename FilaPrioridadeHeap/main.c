//testeFila.c

#include<stdio.h>
#include<stdlib.h>
#include "FilaPrioridade.h"

int main(){
	// Desenvolva os testes para verificar se a função implementada 
  //está funcionando como esperado
  FilaPrioridade* f = filaP_criar();                     
  filaP_inserir(f, 10);                        
  filaP_inserir(f, 9);                         
  filaP_inserir(f, 4);
  filaP_inserir(f, 7);       
  filaP_inserir(f, 8);                  
  filaP_inserir(f, 3);                         
  filaP_inserir(f, 2);                         
  filaP_inserir(f, 6);                         
  filaP_inserir(f, 1);                         
  filaP_inserir(f, 5);                         
  filaP_imprimir(f);
  printf("fila clonada:\n");
  FilaPrioridade* fc = filaP_clone(f);
  filaP_imprimir(fc);       
  printf("fila 2:\n");    
  TipoElemento v[6] = {3,6,5,1,7};        
  FilaPrioridade* f2 = filaP_criar();
  filaP_inserir(f2, 10);                        
  filaP_inserir(f2, 9);                         
  filaP_inserir(f2, 4);
  filaP_inserir(f2, 7);       
  filaP_inserir(f2, 8); 
  filaP_inserirTodos(f2, v, 6);
  filaP_imprimir(f2);   

  printf("%d elementos na fila 1\n", filaP_tamanho(f));
  int removido;
  while(!filaP_vazia(f)){
    filaP_remover(f, &removido);
    printf("%d ", removido);     // saída esperada: 10 9 8 7 6 5 4 3 2 1 
  }
}