//FilaPrioridade com Heap.h
#include <stdio.h>
#include <stdlib.h>
#define T 10
typedef enum boolean{false=0, true=1} Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct {
	TipoElemento* vetor;
	int tam;
	int qtde;
}FilaPrioridade;

/**************************************
* PROTÓTIPOS
**************************************/

FilaPrioridade* filaP_criar();
void filaP_destruir(FilaPrioridade* f);
Boolean filaP_inserir(FilaPrioridade* f, TipoElemento elemento);
Boolean filaP_remover(FilaPrioridade* f, TipoElemento* saida); // estratégia do scanf
Boolean filaP_vazia(FilaPrioridade* f);
int filaP_tamanho(FilaPrioridade* f);
void filaP_imprimir(FilaPrioridade* f);
FilaPrioridade* filaP_clone(FilaPrioridade* f);
Boolean filaP_inserirTodos(FilaPrioridade* f, TipoElemento* vetor, int tamVetor);
//funções extras
void PromoveElemento(FilaPrioridade* f, int filho);
void RebaixaElemento(FilaPrioridade* f, int pai);
/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções

FilaPrioridade* filaP_criar(){
  FilaPrioridade* f = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
  f->vetor = (TipoElemento*) calloc(T,sizeof(TipoElemento));
  f->qtde = 0;
  f->tam = T;
  return f;
}

Boolean filaP_inserir(FilaPrioridade* f, TipoElemento elemento){
  if(f == NULL) return false;
  if(f->qtde == f->tam) return false;

  f->vetor[f->qtde] = elemento;
  PromoveElemento(f,f->qtde);
  f->qtde++;
  return true;
}

void PromoveElemento(FilaPrioridade* f, int filho){
  int pai;
  pai = (filho - 1) / 2;
  while((filho > 0) && (f->vetor[pai] <= f->vetor[filho])){
    int aux = f->vetor[filho];
    f->vetor[filho] = f->vetor[pai];
    f->vetor[pai] = aux;
    filho = pai;
    pai = (pai - 1) / 2;
  }
}

void filaP_destruir(FilaPrioridade* f){
  if(filaP_vazia(f)) return;
  free(f->vetor);
  free(f);
}

Boolean filaP_vazia(FilaPrioridade* f){
  if(f == NULL) return true;
  return (f->qtde == 0);
}

void filaP_imprimir(FilaPrioridade* f){
  if(filaP_vazia(f)) return;

  printf("[%d",f->vetor[0]);
  for(int i = 1; i < f->qtde; i++){
    printf(", %d", f->vetor[i]);
  }
  printf("]\n");
}

Boolean filaP_remover(FilaPrioridade* f, TipoElemento* saida){
  if(filaP_vazia(f)) return false;
  
  f->qtde--;
  *saida = f->vetor[0];
  f->vetor[0] = f->vetor[f->qtde];
  RebaixaElemento(f, 0);
  return true;
}

void RebaixaElemento(FilaPrioridade* f, int pos){
  int aux;
  int filho = 2 * pos + 1;
  while(filho < f->qtde){
    if(filho < f->qtde-1)
      if(f->vetor[filho] < f->vetor[filho+1])
        filho++;
    
    if(f->vetor[pos] >= f->vetor[filho])
      break;

  aux = f->vetor[pos];
  f->vetor[pos] = f->vetor[filho];
  f->vetor[filho] = aux;
  pos = filho;
  filho = 2 * pos + 1;
  }
}

int filaP_tamanho(FilaPrioridade* f){
  return (f->qtde);
}

FilaPrioridade* filaP_clone(FilaPrioridade* f){
  FilaPrioridade *fc = filaP_criar();
  for(int i = 0; i < f->qtde; i++){
    fc->vetor[i] = f->vetor[i];
  }
  fc->qtde = f->qtde;
  fc->tam = f->tam;
  return fc;
}

Boolean filaP_inserirTodos(FilaPrioridade* f, TipoElemento* vetor, int tamVetor){
  if(f == NULL) return false;

  for(int i = 0; i < tamVetor; i++){
    int aux = vetor[i];
    filaP_inserir(f, aux);
  }
  return true;
}