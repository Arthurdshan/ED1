#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false, true} Boolean;

/**************************************
* DATA
**************************************/

typedef struct node{
  int value;
  struct node* prox;
  struct node* ant;
}Node;

typedef struct {
	Node *sentinel;
	int size;
}List;

/**************************************
* PROTOTYPES
**************************************/
List* create_List();
void destroy_list(List* l);
Boolean insert_on_last_position(List* l, int value);
Boolean insert_new_element(List* l, int value, int index);
Boolean remove_from_index(List* l, int index, int* mem_adress);
int remove_element(List* l, int value);
Boolean substitute_element(List* l, int index, int new_element);
int get_position(List* l, int value);
Boolean search_list(List* l, int index, int* mem_adress);
Boolean has_element(List* l, int value);
int get_size(List* l);
Boolean list_to_string(List* l, char* stringAdress);
void print(List* l);

/**************************************
* IMPLEMENTATION
**************************************/

List* create_List(){
  List* l = (List*) malloc(sizeof(List));
  l->size = 0;
  l->sentinel = (Node*) malloc(sizeof(Node));
  return l;
}

void print(List* l){
  int i = 0;
  Node* aux = l->sentinel->prox;

  printf("[");
  while(i < l->size){
    printf("%d", aux->value);
    if(i < l->size - 1)
      printf(", ");
    aux = aux->prox;
    i++;
  }
  printf("]\n\n");
}

void destroy_list(List* l){
  Node* aux = l->sentinel->prox;
  Node* aux2;
  for(int i = 0; i <= l->size; i++){
    aux2 = aux;
    aux = aux->prox;
    free(aux2);
  }
  free(l->sentinel);
  free(l);
}

Boolean insert_on_last_position(List* l, int value){
 if(l->size == 0 || l == NULL) return false;

  Node* insertNode = malloc(sizeof(Node));
  insertNode->value = value;

  insertNode->prox = l->sentinel;
  insertNode->ant = l->sentinel->ant;
  l->sentinel->ant->prox = insertNode;
  l->sentinel->ant = insertNode;
  l->size++;
  return true;
}

Boolean insert_new_element(List* l, int value, int index){
 if(l == NULL || index > l->size + 1 || index <= 0)
    return false;
  index -= 1;

  Node* insertNode = malloc(sizeof(Node));
  insertNode->value = value;

  if(l->size == 0) {
      insertNode->ant = insertNode->prox = l->sentinel;
      l->sentinel->ant = l->sentinel->prox = insertNode;
  }
  else if(index == 0) {
      insertNode->prox = l->sentinel->prox;
      insertNode->ant = l->sentinel;
      l->sentinel->prox = insertNode;
  }
  else if(index == l->size) {
      insertNode->prox = l->sentinel;
      insertNode->ant = l->sentinel->ant;
      l->sentinel->ant->prox = insertNode;
      l->sentinel->ant = insertNode;
  }
  else {
    int i;
    Node* aux;

    if(index <= l->size/2) {
      i=0;
      aux = l->sentinel->prox;
      while(i != index) {
        aux = aux->prox;
        i++;
      }
    }
    else {
      i = l->size;
      aux = l->sentinel->ant;
      while(i != index) {
        aux = aux->ant;
        i--;
      }
    }
   
    insertNode->prox = aux;
    insertNode->ant = aux->ant;
    aux->ant->prox = insertNode;
    aux->ant = insertNode;
  }

  l->size++;
  return true;
}

Boolean remove_from_index(List* l, int index, int* mem_adress){
  if(l == NULL || index <= 0 || index > l->size || l->size == 0) 
    return false;
  index -= 1;

  if(index == l->size - 1 && l->size != 1) {
    *mem_adress = l->sentinel->ant->value;
    l->sentinel->ant->ant->prox = l->sentinel;
    l->sentinel->ant = l->sentinel->ant->ant;
  }
  else if(index == 0 && l->size != 1) {
    *mem_adress = l->sentinel->prox->value;
    l->sentinel->prox->prox->ant = l->sentinel;
    l->sentinel->prox = l->sentinel->prox->prox;
  }
  else if(l->size == 1) {
    *mem_adress = l->sentinel->prox->value;
    l->sentinel->prox = l->sentinel;
    l->sentinel->ant = l->sentinel;
  }
  else{
    int i;
    Node* aux;

    if(index <= l->size/2) {
      i=0;
      aux = l->sentinel->prox;
      while(i != index) {
        aux = aux->prox;
        i++;
      }
    }
    else {
      i = l->size;
      aux = l->sentinel->ant;
      while(i != index) {
        aux = aux->ant;
        i--;
      }
    }
    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;
    *mem_adress = aux->value;
    free(aux);
  }

  l->size--;

  return true;
}

int get_position(List* l, int value) {
  if(l == NULL || l->size == 0)
    return -1;

  int index = 0;
  Node* aux = l->sentinel->prox;
  
  while(index < l->size) {
    if(aux->value != value) {
      aux = aux->prox;
      index += 1;
    }
    else if(aux->value == value){
      break;
    }
  }

  if(aux->value == value) return index + 1;
  else return -1;
}

int remove_element(List *l, int value){
  if(l == NULL) return -1;
  if(l->size == 0) return -1;

  int index;
  index = get_position(l, value);
  if(!index) {
    printf("error\n");
    return -1;
  }
  Node* aux;
  aux = l->sentinel;
  for(int i = 0; i <= l->size; i++){
    if(value == aux->value)
      break;
  aux = aux->prox;
  }
  if(aux != l->sentinel){
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    l->size--;
    free(aux);
    return index;
  }
  return -1;
}

Boolean search_list(List* l, int index, int* mem_adress){
  if(index < 0 || index > l->size)    return false;
  if(l == NULL)   return false;
  if(l->size == 0)    return false;
  Node* aux = l->sentinel->ant;

  for(int i=0; i<=index; i++){
    aux = aux->prox;
  }
  *mem_adress = aux->value;

  return true;
}

Boolean has_element(List* l, int value){
  if(l == NULL) return false;
  Node* aux = l->sentinel->ant;

  while(aux->value != value){
    aux = aux->ant;
    if(aux->prox == l->sentinel){
      printf("value not found.\n\n");
      return false;
    } 
  }
  printf("value found.\n\n");
  return true;
}

int get_size(List* l){
  return l->size;
}

Boolean list_to_string(List* l, char* stringAdress){
  int pos = 0;
  char temp[100];
  Node* aux = l->sentinel->prox;
  stringAdress[pos++] = '[';

   for(int i = 0; i < l->size; i++){
    sprintf(temp, "%d", aux->value);
    int j = 0;
    while(temp[j] != '\0'){
      stringAdress[pos++] = temp[j];
      j++;
    }
    if(i < l->size-1){
      stringAdress[pos++] = ',';
      stringAdress[pos++] = ' ';
    }
    aux = aux->prox;
  }
  stringAdress[pos++] = ']';
  stringAdress[pos] = '\0';

  return true;
}