#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int DataType;

typedef struct{
  DataType* vetor;
  int size;
  int length; 
}Vector;

typedef enum boolean{FALSE, TRUE} Boolean;
typedef int DataType;
#define LENGTH 5

/**
 * ALL FUNCTION PROTOTYPES!
*/
Vector* vet_new(); 
Boolean vet_insertEnd(Vector* v, DataType element);
Boolean vet_insert(Vector* v, DataType element, int index);
Boolean vet_substitute(Vector* v, int index, DataType newElement);
Boolean vet_removePosition(Vector* v, int index, DataType* ptr);
int vet_removeElement(Vector* v, DataType element);
int vet_size(Vector* v);
Boolean vet_element(Vector* v, int index, DataType* exit);
int vet_position(Vector* v, DataType element);
void vet_print(Vector* v);
void vet_free(Vector* v);
Boolean vet_toString(Vector* v,char* enderecoString);
void vetor_double(Vector *v);
void vetor_remove_verify(Vector *v);
void vetor_shift(Vector *v, DataType index);
void vetor_add_verify(Vector *v);
void vetor_reduce(Vector *v);
Vector* vet_clone(Vector* v);
void vet_bubblesort(Vector* v);
void vet_selectionsort(Vector* v);
void trocarPosicaoValores( int *posicaoA, int *posicaoB);
int vet_binarysearch(Vector* v, DataType element);
Vector* vet_import(char* archivename);
Boolean vet_export(Vector* v, char* archivename);
Vector* vet_newrandom(int tam);
Vector* vet_newupward(int tam);
Vector* vet_newdownward(int tam);
Vector* vet_partialupward(int tam, int percentage);

/**
 * IMPLEMENTATIONS!
*/
Vector* vet_new(){
  Vector* v1= (Vector*) malloc(sizeof(Vector));
  v1->vetor = (DataType*) calloc(LENGTH, sizeof(DataType)); 
  v1->size = 0;
  v1->length = LENGTH;
  return v1;
}

Boolean vet_insertEnd(Vector* v, DataType element) {
  if (v == NULL) return FALSE;

  v->vetor[v->size++] = element;
  return TRUE;
}

void vet_free(Vector* v) {
  free(v);
}

void vetor_add_verify(Vector *v){
  printf("**************************\n");
  printf("*checking vector size....*\n");
  printf("**************************\n");
  if(v->size == v->length) vetor_double(v);
}

void vetor_double(Vector *v){
  DataType* aux =(DataType*) calloc(v->length*2, sizeof(DataType));
  for(int i = 0; i < v->size; i++){
    aux[i] = v->vetor[i];
  }
  printf("**********************\n");
  printf("*vector was increased*\n");
  printf("**********************\n");
  v->length *= 2;
  
  free(v->vetor);
  v->vetor = aux;
  
}

void vetor_remove_verify(Vector *v){
  printf("**************************\n");
  printf("*checking if can reduce..*\n");
  printf("**************************\n");
  if((float)v->size/v->length < 0.25){
    vetor_reduce(v);
  }else{
    return;
  }
}

void vetor_reduce(Vector *v){
  DataType *v1 = (DataType*) calloc(v->length/2,sizeof(DataType));
  for(int i = 0; i < v->size; i++){
    v1[i] = v->vetor[i];
  }
  printf("********************\n");
  printf("vector was reduced.*\n");
  printf("********************\n");
  free(v->vetor);
  v->vetor = v1;
  v->length /= 2;
}

void vet_print(Vector* v) {
  if (v == NULL) return;

  int i;
  printf("[");
  for (i=0; i < v->size; i++) {
    printf("%d", v->vetor[i]);
    if (i < v->size-1) printf(", ");
  }
  printf("]");
  printf("\n");
}

void vetor_shift(Vector *v, DataType index){
    DataType *v1 = (DataType*) calloc(v->length,sizeof(DataType));
    for(int i = 0, j = 0; i < v->size; i++, j++){
        if(i == index){
            j++;
            v1[j] = v->vetor[i];
        }
        else{
            v1[j] = v->vetor[i];
        }
    }
    free(v->vetor);
    v->vetor = v1;
}

Boolean vet_insert(Vector* v, DataType element, int index) {
    
    vetor_add_verify(v);

    if(index > v->size || v == NULL) return FALSE;

        else if(index < 0){
          vetor_shift(v,index + v->size);
          v->vetor[index + v->size] = element;
          v->size++;
          return TRUE;
        }else{
          vetor_shift(v,index);
          v->vetor[index] = element;
          v->size++;
          return TRUE;
        }
}

Boolean vet_substitute(Vector* v, int index, DataType newElement){
  if(index > v->size || v == NULL) return FALSE;

  else if(index < 0){
    v->vetor[index + v->size] = newElement;
    return TRUE;
  }
  else{
    v->vetor[index] = newElement;
    return TRUE;
  }
}

Boolean vet_removePosition(Vector* v, int index, DataType* ptr){
  vetor_remove_verify(v);
  if(index > v->size || v == NULL){
    *ptr = 0;
    return FALSE;
  } 
  else {
    if(index < 0){
      ptr = &v->vetor[index+v->size];
      for (int i = index; i < v->size - 1; i++) 
      v->vetor[i] = v->vetor[i+1];
    v->size--;
    return TRUE;
    }
    else{
    ptr = &v->vetor[index];
    for (int i = index; i < v->size - 1; i++) 
      v->vetor[i] = v->vetor[i+1];
    v->size--;
    return TRUE;
    }
  }
}

int vet_removeElement(Vector* v, DataType element){
  vetor_remove_verify(v);
  int z = 0;
  int value;
  for(int i = 0; i < v->size; i++){
    if(v->vetor[i] == element && z == 0){
      for (int j = i; j < v->size - 1; j++) 
      v->vetor[j] = v->vetor[j+1];
    value = i;
    v->size--;
    z++;
    }
  }
  return value;
}

int vet_size(Vector* v){
  return v->size;
}

Boolean vet_element(Vector* v, int index, DataType* exit){
  if(v == NULL || index > v->size) return FALSE;

  else if(index < 0){
    exit = &v->vetor[index+v->size];
    return TRUE;  
  }
  else{
    exit = &v->vetor[index];
    return TRUE;
  }
}


int vet_position(Vector* v, DataType element){ 
  int z = 0, x;
  for(int i = 0; i < v->size; i++){
    if(v->vetor[i] == element && z == 0){
      z = 1;
      x = i;
    }
  }
  return x; 
}

Boolean vet_toString(Vector* v, char* adString){
  int pos = 0;
  int i;
  char temp[20];
  
  adString[pos++] = '[';

  for(i = 0; i < v->size; i++){
    sprintf(temp, "%d", v->vetor[i]);
    int j = 0;
    while(temp[j] != '\0'){
      adString[pos++] = temp[j];
      j++;
    }
     if (i < v->size-1) adString[pos++] = ',';
  }
  adString[pos++] = ']';
  adString[pos] = '\0';
  return TRUE;
}

Vector* vet_clone(Vector* v){

  Vector* copy = (Vector*) malloc(sizeof(Vector));
  copy->vetor = (DataType*) calloc(v->length, sizeof(DataType));
  for(int i = 0; i < v->size; i++){
    copy->vetor[i] = v->vetor[i];
  }
  copy->size = v->size;
  copy->length = v->length;
  return copy;
}

void vet_bubblesort(Vector* v){
  DataType aux;
	int hadc = 1, i, j;
	for(j = v->size-1; j >= 1 && hadc == 1; j--){
		hadc = 0; 
		for(i = 0; i < j; i++){
				if(v->vetor[i]>v->vetor[i+1]){
					aux = v->vetor[i];
					v->vetor[i] = v->vetor[i+1];
					v->vetor[i+1] = aux;
					hadc = 1;
			}
		}
	}
}

void vet_selectionsort(Vector* v){ 
  DataType aux;
  int i, j, min;
  for (i = 0; i < v->size-1; i++){
     min = i;
     for (j = i+1; j < v->size; j++) {
       if(v->vetor[j] < v->vetor[min]) 
         min = j;
     }
     if (v->vetor[i] != v->vetor[min]) {
       aux = v->vetor[i];
       v->vetor[i] = v->vetor[min];
       v->vetor[min] = aux;
     }
  }
}

void vet_insertionsort(Vector* v){ 
    DataType aux;
    int i, j; 
    for (i = 1; i < v->size; i++){ 
        aux = v->vetor[i]; 
        j = i - 1; 
          while (j >= 0 && v->vetor[j] > aux){ 
            v->vetor[j + 1] = v->vetor[j]; 
            j = j - 1; 
        } 
        v->vetor[j + 1] = aux; 
    } 
} 

int vet_binarysearch(Vector* v, DataType element){
  int inf = 0;
  int sup = v->size-1;
  DataType mid;
  while (inf <= sup){
    mid = (inf + sup)/2;
    if (element == v->vetor[mid]) return mid;
  if (element < v->vetor[element]) sup = mid-1;
  else inf = mid+1;
  }
  return -1;
}

Vector* vet_import(char* archivename){

  Vector* v = vet_new();
  FILE *arq;

  arq = fopen(archivename, "r+");
  if (arq != NULL) {
    printf("arquivo aberto.\n");
  }
  else{
    printf("Não foi possível abrir o arquivo!\n");
    return NULL;
  }
  for(int i = 0; i < v->length; i++){
    fscanf(arq,"%d", &v->vetor[i]);
    v->size++;
  }
  fclose(arq);

  return v;
}

Boolean vet_export(Vector* v, char* archivename){
  FILE *arq;

  arq = fopen(archivename, "w+");
  if (arq != NULL) {
    printf("Arquivo aberto.\n");
  }
  else{
    printf("Não foi possível abrir o arquivo!\n");
    return FALSE;
  }
  for(int i = 0; i < v->size; i++)
  fprintf(arq, "%d\n", v->vetor[i]);
  fclose(arq);

  return TRUE;
}

Vector* vet_newrandom(int tam){
  Vector* v = (Vector*) malloc(sizeof(Vector));
  v->vetor = (DataType*) calloc(tam, sizeof(DataType));

  srand(time(NULL));
  for(int i = 0; i < tam; i++){
    v->vetor[i] = rand() % 10;
  }
  v->size = tam;
  v->length = tam;
  return v;
}

Vector* vet_newupward(int tam){
  Vector* v = vet_newrandom(tam);
  vet_insertionsort(v);
  return v;
}

Vector* vet_newdownward(int tam){
  Vector* v = vet_newrandom(tam);

  for (int i = 0; i < tam - 1; i++){
    for (int j = i; j < tam - 1; j++){
      if (v->vetor[i] < v->vetor[j]){
        DataType temp = v->vetor[i];
        v->vetor[i] = v->vetor[j];
        v->vetor[j] = temp;
      }
    }
  }
return v; 
}

Vector* vet_partialupward(int tam, int percentual){
  Vector* v = vet_newrandom(tam);
    DataType aux;
    int i, j;
    for (i = 1; i < (float)v->size*percentual/100; i++){ 
      aux = v->vetor[i]; 
      j = i - 1; 
        while (j >= 0 && v->vetor[j] > aux){ 
          v->vetor[j + 1] = v->vetor[j]; 
          j = j - 1; 
      } 
      v->vetor[j + 1] = aux; 
    } 
  return v;
}
