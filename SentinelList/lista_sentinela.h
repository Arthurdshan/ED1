// lista_sentinela.h
#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct no{
  TipoElemento dado;
  struct no* prox;
  struct no* ant;
}No;

typedef struct {
	No *sentinela;
	int qtde;
}Lista;

/**************************************
* PROTÓTIPOS
**************************************/
Lista* lista_criar();
void lista_destruir(Lista* l);
Boolean lista_inserirFim(Lista* l, TipoElemento elemento);
Boolean lista_inserir(Lista* l, TipoElemento elemento, int posicao);
Boolean lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco);
int lista_removerElemento(Lista* l, TipoElemento elemento);
Boolean lista_substituir(Lista* l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista* l, TipoElemento elemento);
Boolean lista_buscar(Lista* l, int posicao, TipoElemento* endereco);
Boolean lista_contem(Lista* l, TipoElemento elemento);
int lista_tamanho(Lista* l);
Boolean lista_toString(Lista* l, char* enderecoString);
void lista_imprimir(Lista* l);

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções

Lista* lista_criar(){
  Lista* l = (Lista*)malloc (sizeof(Lista));
  l->qtde = 0;
  l->sentinela = (No*)malloc(sizeof(No));
  return l;
}

void lista_imprimir(Lista* l){
  int i = 0;
  No* aux = l->sentinela->prox;

  printf("[");
  while(i < l->qtde){
    printf("%d", aux->dado);
    if(i < l->qtde - 1)
      printf(", ");
    aux = aux->prox;
    i++;
  }
  printf("]\n\n");
}

void lista_destruir(Lista* l){
  No* aux = l->sentinela->prox;
  No* aux2;
  for(int i = 0; i <= l->qtde; i++){
    aux2 = aux;
    aux = aux->prox;
    free(aux2);
  }
  free(l->sentinela);
  free(l);
}

Boolean lista_inserirFim(Lista* l, TipoElemento elemento){
 if(l->qtde == 0 || l == NULL) return false;

  No* noInsere = malloc(sizeof(No));
  noInsere->dado = elemento;

  noInsere->prox = l->sentinela;
  noInsere->ant = l->sentinela->ant;
  l->sentinela->ant->prox = noInsere;
  l->sentinela->ant = noInsere;
  l->qtde++;
  return true;
}

Boolean lista_inserir(Lista* l, TipoElemento elemento, int posicao){
 if(l == NULL || posicao > l->qtde + 1 || posicao <= 0)
    return false;
  posicao -= 1;

  No* noInsere = malloc(sizeof(No));
  noInsere->dado = elemento;

  if(l->qtde == 0) {
      noInsere->ant = noInsere->prox = l->sentinela;
      l->sentinela->ant = l->sentinela->prox = noInsere;
  }
  else if(posicao == 0) {
      noInsere->prox = l->sentinela->prox;
      noInsere->ant = l->sentinela;
      l->sentinela->prox = noInsere;
  }
  else if(posicao == l->qtde) {
      noInsere->prox = l->sentinela;
      noInsere->ant = l->sentinela->ant;
      l->sentinela->ant->prox = noInsere;
      l->sentinela->ant = noInsere;
  }
  else {
    int i;
    No* aux;

    if(posicao <= l->qtde/2) {
      i=0;
      aux = l->sentinela->prox;
      while(i != posicao) {
        aux = aux->prox;
        i++;
      }
    }
    else {
      i = l->qtde;
      aux = l->sentinela->ant;
      while(i != posicao) {
        aux = aux->ant;
        i--;
      }
    }
   
    noInsere->prox = aux;
    noInsere->ant = aux->ant;
    aux->ant->prox = noInsere;
    aux->ant = noInsere;
  }

  l->qtde++;
  return true;
}

Boolean lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
  if(l == NULL || posicao <= 0 || posicao > l->qtde || l->qtde == 0) 
    return false;
  posicao -= 1;

  if(posicao == l->qtde - 1 && l->qtde != 1) {
    *endereco = l->sentinela->ant->dado;
    l->sentinela->ant->ant->prox = l->sentinela;
    l->sentinela->ant = l->sentinela->ant->ant;
  }
  else if(posicao == 0 && l->qtde != 1) {
    *endereco = l->sentinela->prox->dado;
    l->sentinela->prox->prox->ant = l->sentinela;
    l->sentinela->prox = l->sentinela->prox->prox;
  }
  else if(l->qtde == 1) {
    *endereco = l->sentinela->prox->dado;
    l->sentinela->prox = l->sentinela;
    l->sentinela->ant = l->sentinela;
  }
  else{
    int i;
    No* aux;

    if(posicao <= l->qtde/2) {
      i=0;
      aux = l->sentinela->prox;
      while(i != posicao) {
        aux = aux->prox;
        i++;
      }
    }
    else {
      i = l->qtde;
      aux = l->sentinela->ant;
      while(i != posicao) {
        aux = aux->ant;
        i--;
      }
    }
    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;
    *endereco = aux->dado;
    free(aux);
  }

  l->qtde--;

  return true;
}

int lista_posicao(Lista* l, TipoElemento elemento) {
  if(l == NULL || l->qtde == 0)
    return -1;

  int posicao = 0;
  No* aux = l->sentinela->prox;
  
  while(posicao < l->qtde) {
    if(aux->dado != elemento) {
      aux = aux->prox;
      posicao += 1;
    }
    else if(aux->dado == elemento){
      break;
    }
  }

  if(aux->dado == elemento) return posicao + 1;
  else return -1;
}

int lista_removerElemento(Lista *l, TipoElemento elemento){
  if(l == NULL) return -1;
  if(l->qtde == 0) return -1;

  int posicao;
  posicao = lista_posicao(l, elemento);
  if(!posicao) {
    printf("erro\n");
    return -1;
  }
  No* aux;
  aux = l->sentinela;
  for(int i = 0; i <= l->qtde; i++){
    if(elemento == aux->dado)
      break;
  aux = aux->prox;
  }
  if(aux != l->sentinela){
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    l->qtde--;
    free(aux);
    return posicao;
  }
  return -1;
}

Boolean lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
  if(posicao < 0 || posicao > l->qtde)    return false;
  if(l == NULL)   return false;
  if(l->qtde == 0)    return false;
  No* aux = l->sentinela->ant;

  for(int i=0; i<=posicao; i++){
    aux = aux->prox;
  }
  *endereco = aux->dado;

  return true;
}

Boolean lista_contem(Lista* l, TipoElemento elemento){
  if(l == NULL) return false;
  No* aux = l->sentinela->ant;

  while(aux->dado != elemento){
    aux = aux->ant;
    if(aux->prox == l->sentinela){
      printf("Elemento não encontrado.\n\n");
      return false;
    } 
  }
  printf("Elemento encontrado.\n\n");
  return true;
}

int lista_tamanho(Lista* l){
  return l->qtde;
}

Boolean lista_toString(Lista* l, char* enderecoString){
  int pos = 0;
  char temp[100];
  No* aux = l->sentinela->prox;
  enderecoString[pos++] = '[';

   for(int i = 0; i < l->qtde; i++){
    sprintf(temp, "%d", aux->dado);
    int j = 0;
    while(temp[j] != '\0'){
      enderecoString[pos++] = temp[j];
      j++;
    }
    if(i < l->qtde-1){
      enderecoString[pos++] = ',';
      enderecoString[pos++] = ' ';
    }
    aux = aux->prox;
  }
  enderecoString[pos++] = ']';
  enderecoString[pos] = '\0';

  return true;
}