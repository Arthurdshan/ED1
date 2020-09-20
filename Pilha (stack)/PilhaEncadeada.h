//PilhaEncadeada.h
#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/

typedef struct no{
	TipoElemento dado;
	struct no *prox;
}No;

typedef struct {
	No *topo;
	int qtdeElementos;
}Pilha;

/**************************************
* PROTÓTIPOS
**************************************/

Pilha* pilha_criar();
void pilha_destruir(Pilha* p);
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento);
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida); // estratégia do scanf
Boolean pilha_topo(Pilha* p, TipoElemento* saida); // estratégia do scanf
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
  
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  p->qtdeElementos = 0;
  return p;
}

void pilha_destruir(Pilha* p){

  if(p == NULL) return;

  No* aux;
  while(p->topo != NULL){
    aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
  }
  free(p);
}

Boolean pilha_empilhar(Pilha* p, TipoElemento elemento){
  
  if(p == NULL) return false;
  
  No* no = (No*) malloc(sizeof(No));
  if(no == NULL) return false;
  no->dado = elemento;

  no->prox = p->topo;
  p->qtdeElementos++;
  p->topo = no;
  return true;
}

Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida){
  
  if(p == NULL || p->topo == NULL) return false;

  *saida = p->topo->dado;
  No* aux = p->topo;
  p->topo = aux->prox;
  p->qtdeElementos--; 
  free(aux);
  return true;
}

void pilha_imprimir(Pilha* p){
  
  No* teste = p->topo;
  while(teste != NULL){
    printf("%d -> ", teste->dado);
    teste = teste->prox;
  }
  printf("NULL\n");
}

Boolean pilha_topo(Pilha* p, TipoElemento* saida){
  
  if (p == NULL || p->topo == NULL) return false;

  *saida = p->topo->dado;
  return true; 
}

int pilha_tamanho(Pilha* p){
  return p->qtdeElementos;
}

Pilha* pilha_clone(Pilha* p){
  
  Pilha* clone = (Pilha*) malloc(sizeof(Pilha));
  No* caminho = p->topo;
  No* temp;
  for(int i = 0; i < p->qtdeElementos; i++){
    No* dado = (No*) malloc(sizeof(No));
    dado->dado = caminho->dado;
      
    if(i == 0) clone->topo = dado;
    else temp->prox = dado;
      
    temp = dado;
    caminho = caminho->prox;
  }
  return clone;
}

void pilha_inverter(Pilha* p){
  
  Pilha* p1 = pilha_criar();
  No* aux = p->topo;
  while(aux != NULL){
    pilha_empilhar(p1,aux->dado);
    aux = aux->prox;
  }
  p1->qtdeElementos = p->qtdeElementos;
  p->topo = p1->topo;
}

Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){

  if (p == NULL) return false;

  for(int i = 0; i < tamVetor; i++){
    int aux = vetor[i];
    pilha_empilhar(p, aux);
    p->qtdeElementos++;
  }
  return true;
}