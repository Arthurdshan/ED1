#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct{
	int code;
	char description[120];
	float price;
}Product;

typedef struct{
	Product* vector;
	int length;
	int size;
}Vector;

typedef Product DataType;
typedef enum boolean{false=0, true=1} Boolean;
#define LENGTH 5
//#define POSICAO_INVALIDA

/*prototypes*/
//part 1
Vector* vet_new();
Product* create_product(int code, char* description, float price);
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
//vector part 2 
void vetor_double(Vector *v);
void vetor_remove_verify(Vector *v);
void vetor_shift(Vector *v, int index);
void vetor_add_verify(Vector *v);
void vetor_reduce(Vector *v);
Vector* vet_clone(Vector* v);
void vet_bubblesort(Vector* v);
void vet_selectionsort(Vector* v);
void trocarPosicaoValores( int *posicaoA, int *posicaoB);
int vet_binarysearch(Vector* v, DataType element);
//vector part 3
Vector* vet_import(char* archivename);
Boolean vet_export(Vector* v, char* archivename);


Vector* vet_new(){
  Vector* v1= (Vector*) malloc(sizeof(Vector));
  v1->vector = (DataType*) calloc(LENGTH, sizeof(DataType)); 
  v1->size = 0;
  v1->length = LENGTH;
  return v1;
}

Product* create_product(int code, char* description, float price){
  Product* p1= (Product*) malloc(sizeof(Product));
  p1->code = code;
  strcpy(p1->description, description);
  p1->price = price;
  return p1;
}

Boolean vet_insertEnd(Vector* v, DataType element) {

  vetor_add_verify(v);

  if (v == NULL) return false;

  v->vector[v->size++] = element;
  return true;
}

void vet_free(Vector* v) {
  free(v);
}

void vetor_add_verify(Vector *v){
  if(v->size == v->length) vetor_double(v);
  else return;
}

void vetor_double(Vector *v){
  DataType* aux = calloc(v->length*2, sizeof(DataType));
  for(int i = 0; i < v->size; i++){
    aux[i] = v->vector[i];
  }
  v->length *= 2;
  
  free(v->vector);
  v->vector = aux;
  
}

void vetor_remove_verify(Vector *v){
  if((float)v->size/v->length < 0.25){
    vetor_reduce(v);
  }else{
    return;
  }
}

void vetor_reduce(Vector *v){
  DataType *v1 = (DataType*) calloc(v->length/2,sizeof(DataType));
  for(int i = 0; i < v->size; i++){
    v1[i] = v->vector[i];
  }
  free(v->vector);
  v->vector = v1;
  v->length /= 2;
}

void vet_print(Vector* v){
  if (v == NULL) return;
  
  int i;
  printf("\n");
  for (i=0; i < v->size; i++) {
    printf("[%d, ", v->vector[i].code);
    
    printf("%s, ", v->vector[i].description);

    printf("%.2f]\n", v->vector[i].price);
  }
  printf("\n");
}

void vetor_shift(Vector *v, int index){
    DataType *v1 = (DataType*) calloc(v->length,sizeof(DataType));
    for(int i = 0, j = 0; i < v->size; i++, j++){
        if(i == index){
            j++;
            v1[j] = v->vector[i];
        }
        else{
            v1[j] = v->vector[i];
        }
    }
    free(v->vector);
    v->vector = v1;
}

Boolean vet_insert(Vector* v, DataType element, int index) {
    
    vetor_add_verify(v);

    if(index > v->size || v == NULL) return false;

        else if(index < 0){
          vetor_shift(v,index + v->size);
          v->vector[index + v->size] = element;
          v->size++;
          return true;
        }else{
          vetor_shift(v,index);
          v->vector[index] = element;
          v->size++;
          return true;
        }
}

Boolean vet_substitute(Vector* v, int index, DataType newElement){
  if(index > v->size || v == NULL) return false;

  else if(index < 0){
    v->vector[index + v->size] = newElement;
    return true;
  }
  else{
    v->vector[index] = newElement;
    return true;
  }
}

Boolean vet_removePosition(Vector* v, int index, DataType* ptr){
  
  vetor_remove_verify(v);
  
  if(index > v->size || v == NULL){
    ptr = 0;
    return false;
  } 
  else if(index < 0){
    ptr = &v->vector[index+v->size];
    for (int i = index+v->size; i < v->size - 1; i++) 
    v->vector[i] = v->vector[i+1];
    v->size--;
    return true;
    }
    else{
    ptr = &v->vector[index];
    for (int i = index+v->size; i < v->size - 1; i++) 
      v->vector[i] = v->vector[i+1];
    v->size--;
    return true;
    }
  }

int vet_removeElement(Vector* v, DataType element){
  vetor_remove_verify(v);
  int z = 0;
  int value;
  for(int i = 0; i < v->size; i++){
    if(v->vector[i].code == element.code && z == 0){
      for (int j = i; j < v->size - 1; j++) 
      v->vector[j] = v->vector[j+1];
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
  if(v == NULL || index > v->size) return false;

  else if(index < 0){
    exit = &v->vector[index+v->size];
    return true;  
  }
  else{
    exit = &v->vector[index];
    return true;
  }
}


int vet_position(Vector* v, DataType element){ 
  int x;
  for(int i = 0; i < v->size; i++)
    if(v->vector[i].code == element.code) x = i;
  if(x >= 0) return x;
  else return -1;
  
}

Boolean vet_toString(Vector* v, char* enderecoString){
    if(v == NULL){
      return false;
    }

    char temp[120];
    int j = 0, pos = 0, i;

    for (i = 0; i < v->size; i++){
        enderecoString[pos++] = '[';
        sprintf(temp, "%d", v->vector[i].code);
        while (temp[j] != '\0'){
            enderecoString[pos++] = temp[j++];
        }
        j = 0;

        enderecoString[pos++] = ',';
        enderecoString[pos++] = ' ';

        strcpy(temp, v->vector[i].description);
        while (temp[j] != '\0'){
            enderecoString[pos++] = temp[j++];
        }
        j = 0;

        enderecoString[pos++] = ',';
        enderecoString[pos++] = ' ';

        sprintf(temp, "%f", v->vector[i].price);
        while (temp[j] != '\0'){
            enderecoString[pos++] = temp[j++];
        }
        j = 0;

        enderecoString[pos++] = ']';

        if(i != v->size - 1){
            enderecoString[pos++] = '\n';
        }
    }
    enderecoString[pos] = '\0';

    return true;
}
Vector* vet_clone(Vector* v){

  Vector* copy = (Vector*) malloc(sizeof(Vector));
  copy->vector = (DataType*) calloc(v->length, sizeof(DataType));
  for(int i = 0; i < v->size; i++){
    copy->vector[i] = v->vector[i];
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
				if(v->vector[i].code >v->vector[i+1].code){
					aux = v->vector[i];
					v->vector[i] = v->vector[i+1];
					v->vector[i+1] = aux;
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
       if(v->vector[j].code < v->vector[min].code) 
         min = j;
     }
     if (v->vector[i].code != v->vector[min].code) {
       aux = v->vector[i];
       v->vector[i] = v->vector[min];
       v->vector[min] = aux;
     }
  }
}

void vet_insertionsort(Vector* v){ 
    DataType aux;
    int i, j; 
    for (i = 1; i < v->size; i++){ 
        aux = v->vector[i]; 
        j = i - 1; 
          while (j >= 0 && v->vector[j].code > aux.code){ 
            v->vector[j + 1] = v->vector[j]; 
            j = j - 1; 
        } 
        v->vector[j + 1] = aux; 
    } 
} 

int vet_binarysearch(Vector* v, DataType element){
  int inf = 0;
  int sup = v->size-1;
  int mid;
  while (inf <= sup){
    mid = (inf + sup)/2;
    if (element.code == v->vector[mid].code)
      return mid;
  if (element.code < v->vector[mid].code)
    sup = mid-1;
  else
    inf = mid+1;
  }
  return -1;
}

Vector* vet_import(char* archivename){
  
  Vector* v = vet_new();
  FILE *arq;

  arq = fopen(archivename, "r");

  if (arq == NULL) {
    return NULL;
  }
  else{
    printf("arquivo aberto\n");
  }
   int c;
    int cont = 0;
    while((c = fgetc(arq)) != EOF) if(c == '\n') cont++;
    while(v->length < cont) vetor_double(v);
    v->size = cont+1;
    rewind(arq);   

  char str[500], delim[] = "|";
    int j = 0;
  for(int i = 0; i < v->size; i++){

    fgets(str, sizeof(str), arq);
    char *ptr = strtok(str, delim);

    int teste1 = 0;
    while(ptr != NULL) {
        if(teste1 == 0) {
          int teste3 = atoi(ptr);
          v->vector[j].code = teste3;
          teste1 = 1;
        }else if(teste1 == 1) {
          strcpy(v->vector[j].description, ptr);
          teste1 = 2;
        }else{
          float teste4 = atof(ptr);
          v->vector[j].price = teste4;
          teste1 = 0;
          j++;
        }
      ptr = strtok(NULL, delim);
    }
  }

  fclose(arq);
  
  return v;
}

Boolean vet_export(Vector* v, char* archivename){
  
  FILE *arq;

  arq = fopen(archivename, "w+");
  
  if (arq != NULL) printf("\nArquivo aberto.\n");
  else{
    printf("Não foi possível abrir o arquivo!\n");
    return false;
  }
  for(int i = 0; i < v->size; i++){
  fprintf(arq, "[%d, ", v->vector[i].code);
  fprintf(arq, "%s,", v->vector[i].description);
  fprintf(arq, "%.2f]\n", v->vector[i].price);

  }
  fclose(arq);

  return true;
}