#include "pilha.h"


/**************************************
* DADOS
**************************************/

typedef struct {
	Pilha* p1;
    Pilha* p2;
	int qtdeElementos;
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


/**************************************
* EXERCICIO 02
**************************************/

Fila* fila_criar(){
   Fila *f = (Fila*) malloc(sizeof(Fila));
   f->qtdeElementos = 0;
   f->p1 = pilha_criar();
   f->p2 = pilha_criar();
   return f;
}

void fila_destruir(Fila* f){
   
}

Boolean fila_inserir(Fila* f, TipoElemento elemento){
   if(f == NULL) return false;
   while(!pilha_vazia(f->p2)){
      TipoElemento elem;
      pilha_desempilhar(f->p2, &elem);
      pilha_empilhar(f->p1, elem);
   }
   pilha_empilhar(f->p1, elemento);
   f->qtdeElementos++;
   return true;
}

Boolean fila_remover(Fila* f, TipoElemento* saida){ // estratégia do scanf
   if(f == NULL || pilha_vazia(f->p2) && pilha_vazia(f->p1)) return false;
   while(!pilha_vazia(f->p1)){
      TipoElemento elem;
      pilha_desempilhar(f->p1, &elem);
      pilha_empilhar(f->p2, elem);
   }
   pilha_desempilhar(f->p2, saida);
   f->qtdeElementos++;
   return true;
}

Boolean fila_primeiro(Fila* f, TipoElemento* saida){// estratégia do scanf
   if(f == NULL || pilha_vazia(f->p2) && pilha_vazia(f->p1)) return false;
   while(!pilha_vazia(f->p1)){
      TipoElemento elem;
      pilha_desempilhar(f->p1, &elem);
      pilha_empilhar(f->p2, elem);
   }
   pilha_topo(f->p2, saida);
   return true;
}

Boolean fila_vazia(Fila* f){

}



