//teste_lista.c

#include<stdio.h>
#include<stdlib.h>
#include "lista_sentinela.h"


int main(){
	// Desenvolva os testes para verificar se a função implementada 
  //está funcionando como esperado
  Lista* l = lista_criar();
  printf("inserindo no inicio\t");
  lista_inserir(l, 1, 1);
  lista_imprimir(l);

  printf("inserindo no final\t");
  lista_inserirFim(l, 2);
  lista_imprimir(l);

  printf("inserindo no final\t");
  lista_inserirFim(l, 3);
  lista_imprimir(l);

  printf("inserindo no final\t");
  lista_inserirFim(l, 4);
  lista_imprimir(l);

  printf("inserindo no final\t");
  lista_inserirFim(l, 5);
  lista_imprimir(l);

  printf("inserindo no final\t");
  lista_inserirFim(l, 6);
  lista_imprimir(l);

  printf("inserindo no final\t");
  lista_inserirFim(l, 7);
  lista_imprimir(l);

  printf("inserindo na posição 2\t");
  lista_inserir(l, 8, 2);
  lista_imprimir(l);

  printf("--------------------------------------\n\n");
  
  printf("removendo pelo metodo do scanf\n");
  int remover;
  lista_removerPosicao(l, 3, &remover);
  printf("removido = %d\t", remover);
  lista_imprimir(l);

  printf("--------------------------------------\n\n");

  printf("Buscando posição do elemento\n");
  int pos = lista_posicao(l, 1);
  printf("1 está na posição: %d\n\n", pos);
  
  int pos1 = lista_posicao(l, 7);
  printf("7 está na posição: %d\n\n", pos1);
  
  int pos2 = lista_posicao(l, 10);
  printf("10 está na posição: %d\n\n", pos2);

  printf("--------------------------------------\n\n");
  
  printf("removendo elemento 10\n");
  remover = lista_removerElemento(l, 10);
  
  if(remover == -1) printf("erro na remoção/elemento inexistente.\n\n");
  else {
    printf("posição do elemento removido : %d\t", remover);
    lista_imprimir(l);
  }
  
  printf("removendo elemento 8\n");

  remover = lista_removerElemento(l, 8);
  if(remover == -1) printf("erro na remoção/elemento inexistente.\n\n");
  else {
    printf("posição do elemento removido : %d\t", remover);
    lista_imprimir(l);
  }
  
  printf("--------------------------------------\n\n");
  
  printf("buscando elemento pela posição\n");
  int endereco;
  lista_buscar(l, 3, &endereco);
  printf("o elemento %d se encontra na posição 3.\n\n", endereco);

  printf("--------------------------------------\n\n");
  
  printf("verificando se a fila possui o elemento 1\n");
  lista_contem(l, 1);
  printf("verificando se a fila possui o elemento 505\n");
  lista_contem(l, 505);

  printf("--------------------------------------\n\n");
  
  printf("passando a fila para string\n");
  char enderecoString[100];
  lista_toString(l, enderecoString);
  printf("%s\n", enderecoString);
}