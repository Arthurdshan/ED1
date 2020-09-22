#include <stdio.h>
#include <stdlib.h>
#define N 5

//PilhaContigua.h

typedef enum boolean{false=0, true=1} Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct {
	TipoElemento* vetor;
	int tam;
	int qtde;
}Pilha;

/**************************************
* PROTÓTIPOS
**************************************/
Pilha* pilha_criar();
void pilha_destruir(Pilha* p);
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento);
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida);
Boolean pilha_topo(Pilha* p, TipoElemento* saida);
void pilha_imprimir(Pilha* p);
int pilha_tamanho(Pilha* p);
Pilha* pilha_clone(Pilha* p);
void pilha_inverter(Pilha* p);
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor);

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções

Pilha* pilha_criar(){
  Pilha* p1= (Pilha*) malloc(sizeof(Pilha));
  p1->vetor = (TipoElemento*) calloc(N, sizeof(TipoElemento)); 
  p1->qtde = 0;
  p1->tam = N;
  return p1;
}

void pilha_destruir(Pilha* p){
  free(p->vetor);
  free(p);
}

Boolean pilha_empilhar(Pilha* p, TipoElemento elemento){
  if(p == NULL) return false;
  if(p->qtde == p->tam) return false;
  p->vetor[p->qtde] = elemento;
  p->qtde++;
  return true;
}

Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida){
  if(p == NULL || p->qtde == 0) return false;

  *saida = p->vetor[p->qtde - 1];
  p->qtde--;
  return true;
  }

Boolean pilha_topo(Pilha* p, TipoElemento* saida){
  if (p == NULL) return false;

  saida = &p->vetor[p->qtde];
  return true; 
}

void pilha_imprimir(Pilha *p){
  if (p == NULL) return;
  
  for(int i = 0; i < p->qtde; i++){
    if(i == p->qtde-1) printf("%d\n", p->vetor[i]);
    else printf("%d -> ", p->vetor[i]);
    
  }
}

int pilha_tamanho(Pilha* p){
  return p->qtde;
}

Pilha* pilha_clone(Pilha* p){
  Pilha* p1= pilha_criar();
  p1->tam = p->tam;
  p1->qtde = p->qtde;
  for(int i = 0; i < p->qtde; i++){
    p1->vetor[i] = p->vetor[i];
  }
  return p1;
}

void pilha_inverter(Pilha* p){
  
  if(p == NULL) return;

  TipoElemento* inverso = (TipoElemento*) calloc(p->tam, sizeof(TipoElemento));
  for(int i = p->qtde - 1, j = 0; i >= 0; i--, j++){
    inverso[j] = p->vetor[i];
  }
  free(p->vetor);
  p->vetor = inverso;
}

Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
  if (p == NULL|| tamVetor <= 0) return false;

  for(int i = 0; i < tamVetor; i++){
    pilha_empilhar(p, vetor[i]);
  }
  return true;
}
