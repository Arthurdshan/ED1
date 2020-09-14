#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int DataType;

typedef struct{
  DataType* vetor;
  int size;
  int length; 
}Vetor;

typedef enum boolean{false=0, true=1} Boolean;
typedef int DataType;
#define LENGTH 5
//#define POSICAO_INVALIDA

/*prototypes*/
//part 1
Vetor* vet_new();
Boolean vet_insertEnd(Vetor* v, DataType element);
Boolean vet_insert(Vetor* v, DataType element, int index);
Boolean vet_substitute(Vetor* v, int index, DataType newElement);
Boolean vet_removePosition(Vetor* v, int index, DataType* ptr);
int vet_removeElement(Vetor* v, DataType element);
int vet_size(Vetor* v);
Boolean vet_element(Vetor* v, int index, DataType* exit);
int vet_position(Vetor* v, DataType element);
void vet_print(Vetor* v);
void vet_free(Vetor* v);
Boolean vet_toString(Vetor* v,char* enderecoString);
//vetor part 2 
void vetor_double(Vetor *v);
void vetor_remove_verify(Vetor *v);
void vetor_shift(Vetor *v, DataType index);
void vetor_add_verify(Vetor *v);
void vetor_reduce(Vetor *v);
Vetor* vet_clone(Vetor* v);
void vet_bubblesort(Vetor* v);
void vet_selectionsort(Vetor* v);
void trocarPosicaoValores( int *posicaoA, int *posicaoB);
int vet_binarysearch(Vetor* v, DataType element);
//vetor part 3
Vetor* vet_import(char* archivename);
Boolean vet_export(Vetor* v, char* archivename);
//vetor part 4
Vetor* vet_newrandom(int tam);
Vetor* vet_newupward(int tam);
Vetor* vet_newdownward(int tam);
Vetor* vet_partialupward(int tam, int percentage);


Vetor* vet_new(){
  Vetor* v1= (Vetor*) malloc(sizeof(Vetor));
  v1->vetor = (DataType*) calloc(LENGTH, sizeof(DataType)); 
  v1->size = 0;
  v1->length = LENGTH;
  return v1;
}

Boolean vet_insertEnd(Vetor* v, DataType element) {
  if (v == NULL) return false;

  v->vetor[v->size++] = element;
  return true;
}

void vet_free(Vetor* v) {
  free(v);
}

void vetor_add_verify(Vetor *v){
  printf("***************************\n");
  printf("*testando se pode aumentar*\n");
  printf("***************************\n");
  if(v->size == v->length) vetor_double(v);
}

void vetor_double(Vetor *v){
  DataType* aux = calloc(v->length*2, sizeof(DataType));
  for(int i = 0; i < v->size; i++){
    aux[i] = v->vetor[i];
  }
  printf("*********************\n");
  printf("*vetor foi aumentado*\n");
  printf("*********************\n");
  v->length *= 2;
  
  free(v->vetor);
  v->vetor = aux;
  
}

void vetor_remove_verify(Vetor *v){
  printf("**************************\n");
  printf("*testando se pode reduzir*\n");
  printf("**************************\n");
  if((float)v->size/v->length < 0.25){
    vetor_reduce(v);
  }else{
    return;
  }
}

void vetor_reduce(Vetor *v){
  DataType *v1 = (DataType*) calloc(v->length/2,sizeof(DataType));
  for(int i = 0; i < v->size; i++){
    v1[i] = v->vetor[i];
  }
  printf("********************\n");
  printf("vetor foi reduzido.\n");
  printf("********************\n");
  free(v->vetor);
  v->vetor = v1;
  v->length /= 2;
}

void vet_print(Vetor* v) {
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

void vetor_shift(Vetor *v, DataType index){
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

Boolean vet_insert(Vetor* v, DataType element, int index) {
    
    vetor_add_verify(v);

    if(index > v->size || v == NULL) return false;

        else if(index < 0){
          vetor_shift(v,index + v->size);
          v->vetor[index + v->size] = element;
          v->size++;
          return true;
        }else{
          vetor_shift(v,index);
          v->vetor[index] = element;
          v->size++;
          return true;
        }
}

Boolean vet_substitute(Vetor* v, int index, DataType newElement){
  if(index > v->size || v == NULL) return false;

  else if(index < 0){
    v->vetor[index + v->size] = newElement;
    return true;
  }
  else{
    v->vetor[index] = newElement;
    return true;
  }
}

Boolean vet_removePosition(Vetor* v, int index, DataType* ptr){
  vetor_remove_verify(v);
  if(index > v->size || v == NULL){
    *ptr = 0;
    return false;
  } 
  else {
    if(index < 0){
      ptr = &v->vetor[index+v->size];
      for (int i = index; i < v->size - 1; i++) 
      v->vetor[i] = v->vetor[i+1];
    v->size--;
    return true;
    }
    else{
    ptr = &v->vetor[index];
    for (int i = index; i < v->size - 1; i++) 
      v->vetor[i] = v->vetor[i+1];
    v->size--;
    return true;
    }
  }
}

int vet_removeElement(Vetor* v, DataType element){
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

int vet_size(Vetor* v){
  return v->size;
}

Boolean vet_element(Vetor* v, int index, DataType* exit){
  if(v == NULL || index > v->size) return false;

  else if(index < 0){
    exit = &v->vetor[index+v->size];
    return true;  
  }
  else{
    exit = &v->vetor[index];
    return true;
  }
}


int vet_position(Vetor* v, DataType element){ 
  int z = 0, x;
  for(int i = 0; i < v->size; i++){
    if(v->vetor[i] == element && z == 0){
      z = 1;
      x = i;
    }
  }
  //if(x == NULL) return POSICAO_INVALIDA;
  return x; 
}

Boolean vet_toString(Vetor* v, char* adString){
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
  return true;
}

Vetor* vet_clone(Vetor* v){

  Vetor* copy = (Vetor*) malloc(sizeof(Vetor));
  copy->vetor = (DataType*) calloc(v->length, sizeof(DataType));
  for(int i = 0; i < v->size; i++){
    copy->vetor[i] = v->vetor[i];
  }
  copy->size = v->size;
  copy->length = v->length;
  return copy;
}

void vet_bubblesort(Vetor* v){
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

void vet_selectionsort(Vetor* v){ 
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

void vet_insertionsort(Vetor* v){ 
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

int vet_binarysearch(Vetor* v, DataType element){
  int inf = 0;
  int sup = v->size-1;
  DataType mid;
  while (inf <= sup){
    mid = (inf + sup)/2;
    if (element == v->vetor[mid])
      return mid;
  if (element < v->vetor[element])
    sup = mid-1;
  else
    inf = mid+1;
  }
  return -1;
}

Vetor* vet_import(char* archivename){

  Vetor* v = vet_new();
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

Boolean vet_export(Vetor* v, char* archivename){
  FILE *arq;

  arq = fopen(archivename, "w+");
  if (arq != NULL) {
    printf("Arquivo aberto.\n");
  }
  else{
    printf("Não foi possível abrir o arquivo!\n");
    return false;
  }
  for(int i = 0; i < v->size; i++)
  fprintf(arq, "%d\n", v->vetor[i]);
  fclose(arq);

  return true;
}

Vetor* vet_newrandom(int tam){
  Vetor* v = (Vetor*) malloc(sizeof(Vetor));
  v->vetor = (DataType*) calloc(tam, sizeof(DataType));

  srand(time(NULL));
  for(int i = 0; i < tam; i++){
    v->vetor[i] = rand() % 10;
  }
  v->size = tam;
  v->length = tam;
  return v;
}

Vetor* vet_newupward(int tam){
  Vetor* v = vet_newrandom(tam);
  vet_insertionsort(v);
  return v;
}

Vetor* vet_newdownward(int tam){
  Vetor* v = vet_newrandom(tam);

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

Vetor* vet_partialupward(int tam, int percentual){
  Vetor* v = vet_newrandom(tam);
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
