//FilaCircular.h
#include<stdio.h>
#include<stdlib.h>
#define MAX 8

typedef enum boolean{false=0, true=1} Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct {
	TipoElemento* vetor;
	int tam;
	int inicio;
	int fim;
	int qtde;
}Fila;

/**************************************
* PROTÓTIPOS
**************************************/

Fila* fila_criar();
void fila_destruir(Fila* f);
Boolean fila_inserir(Fila* f, TipoElemento elemento);
Boolean fila_remover(Fila* f, TipoElemento* saida); // estratégia do scanf
Boolean fila_primeiro(Fila* f, TipoElemento* saida); // estratégia do scanf
Boolean fila_vazia(Fila* f);
int fila_tamanho(Fila* f);
void fila_imprimir(Fila* f);
Fila* fila_clone(Fila* f);
void fila_inverter(Fila* f);
Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor);

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções
Fila* fila_criar(){
  Fila* fila = (Fila*) malloc(sizeof(Fila));
  fila->vetor = (TipoElemento*) calloc(MAX, sizeof(TipoElemento));
  
  if(fila != NULL){
  fila->tam = MAX;
	fila->inicio = 0;
	fila->fim = 0;
	fila->qtde = 0;
  }
  return fila;
}
void fila_imprimir(Fila* f){
  printf("[");
  for(int i = f->inicio; i < f->fim; i++){
    if(i == f->inicio)
      printf("%d",f->vetor[i%f->tam]);
    else
      printf(", %d",f->vetor[i%f->tam]);
    }
    printf("]\n");
}
void fila_destruir(Fila* f){
  free(f->vetor);
  free(f);
}

Boolean fila_inserir(Fila* f, TipoElemento elemento){
  if(f == NULL || f->qtde == MAX) {
  printf("fila cheia.\n");
  return false;
  }else{
  f->vetor[f->fim] = elemento;
  f->fim = (f->fim+1) % MAX;
  f->qtde++;
  return true;
  }
}

Boolean fila_remover(Fila* f, TipoElemento* saida){
  if(f == NULL || fila_vazia(f)) return false;
  
  *saida = f->vetor[f->inicio%f->tam]; 
  f->inicio = (f->inicio+1) % MAX;
  f->qtde--;
  return true;
}

Boolean fila_primeiro(Fila* f, TipoElemento* saida){
  if(fila_vazia(f)) return false;
  else{
    *saida = f->vetor[f->inicio];
    return true;
  }
}

Boolean fila_vazia(Fila* f){
  if(f == NULL) return -1;
  if(f->qtde == 0) return true;
  else return false;
}

int fila_tamanho(Fila* f){
  return (f->fim - f->inicio);
}

Fila* fila_clone(Fila* f){
  Fila* fc = fila_criar();
  for(int i = f->inicio; i < f->fim; i++){
    fila_inserir(fc, f->vetor[i]);
  }
  fc->qtde = f->qtde;
  fc->tam = f->tam;
  return fc;
}

void fila_inverter(Fila* f){
  TipoElemento* inverso = (TipoElemento*) calloc(f->tam, sizeof(TipoElemento));
  for(int i = f->qtde - 1, j = 0; i >= 0; i--, j++){
    inverso[j] = f->vetor[i];
  }
  free(f->vetor);
  f->vetor = inverso;
}

Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor){
  for(int i = 0; i < tamVetor; i++){
    fila_inserir(f, vetor[i]);
  }
  return true;
}