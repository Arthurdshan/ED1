//FilaEncadeada.h
#include<stdio.h>
#include<stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

typedef struct {
	No *inicio;
	No *fim;
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
  Fila *f = (Fila*) malloc(sizeof(Fila));
  if(f != NULL) {
    f->inicio = NULL;
    f->fim = NULL;
    f->qtde = 0;
  }
  return f;
}

void fila_destruir(Fila* f){
  if(f != NULL){
    No* aux;
    while(f->inicio != NULL){
      aux = f->inicio;
      f->inicio = f->inicio->prox;
      free(aux);
    }
    free(f);
  }
}

Boolean fila_inserir(Fila* f, TipoElemento elemento){
  if(f == NULL) return false;
  No* no = (No*) malloc (sizeof(No*));
  if(no == NULL) return false;
  no->dado = elemento;
  no->prox = NULL;

  if(fila_vazia(f)) 
    f->inicio = no;
  else 
    f->fim->prox = no;
  f->fim = no;
  f->qtde++;
  return true;
}

Boolean fila_remover(Fila* f, TipoElemento* saida){
  if(fila_vazia(f)) return false;
  No* no = f->inicio;
  *saida = no->dado;
  f->inicio = f->inicio->prox;
  if(f->inicio == NULL) f->fim = NULL;
  free(no);
  f->qtde--;
  return true;
}

Boolean fila_primeiro(Fila* f, TipoElemento* saida){
  if(fila_vazia(f)) return false;
  *saida = f->inicio->dado;
  return true;
}

int fila_tamanho(Fila* f){
  if(f == NULL) return 0;
return f->qtde;
}

Boolean fila_vazia(Fila* f){
  if(f == NULL) return true;
  if(f->inicio == NULL) return true;
  return false;
}

void fila_imprimir(Fila *f){
  No* aux = f->inicio;
  for(int i = 0; i < f->qtde; i++){
      printf("%d -> ",aux->dado);
      aux = aux->prox;
  }
  printf("NULL\n");
}

Fila* fila_clone(Fila* f){
  if(fila_vazia(f)) return NULL;

  Fila* clone = (Fila*) malloc(sizeof(Fila));
  No* caminho = f->inicio;
  No* temp;
  for(int i = 0; i < f->qtde; i++){
    No* dado = (No*) malloc(sizeof(No));
    dado->dado = caminho->dado;

    if(i == 0) clone->inicio = dado;
    else temp->prox = dado;
    
    temp = dado;
    caminho = caminho->prox;
  }
  clone->qtde = f->qtde;
return clone;
}

void fila_inverter(Fila* f){
  No* aux = NULL; 
  No* aux1 = f->inicio; 
  No* aux2 = NULL; 
  while (aux1 != NULL) { 
    aux2 = aux1->prox; 
    aux1->prox = aux; 
    aux = aux1; 
    aux1 = aux2; 
  } 
  f->inicio = aux; 
}

Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor){
  if (f == NULL) return false;

  for(int i = 0; i < tamVetor; i++){
    int aux = vetor[i];
    fila_inserir(f, aux);
  }
  return true;
}
