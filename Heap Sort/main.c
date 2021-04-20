#include <time.h>
#include <stdio.h>
#include <string.h>
#include "box_office.h"

int main(){

  clock_t time;
  char caseFile[] = "cases/case1.txt";

  time = clock();
  printf("case 1: R$ %.3f\n", get_profit(caseFile));
  time = clock() - time;
  printf("execution time was: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);

  time = clock();
  strcpy(caseFile, "cases/case2.txt");
  printf("case 2: R$% .3f\n", get_profit(caseFile));
  time = clock() - time;
  printf("execution time was: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);
  
  time = clock();
  strcpy(caseFile, "cases/case3.txt");
  printf("case 3: R$ %.3f\n", get_profit(caseFile));
  time = clock() - time;
  printf("execution time was: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);  
  
  time = clock();
  strcpy(caseFile, "cases/case4.txt");
  printf("case 4: R$ %.3f\n", get_profit(caseFile));
  time = clock() - time;
  printf("execution time was: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);
  
  time = clock();
  strcpy(caseFile, "cases/case5.txt");
  printf("case 5: R$ %.3f\n", get_profit(caseFile));
  time = clock() - time;
  printf("execution time was: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);

  time = clock();
  strcpy(caseFile, "cases/case6.txt");
  printf("case 6: R$ %.3f\n", get_profit(caseFile));
  time = clock() - time;
  printf("execution time was: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);

  time = clock();
  strcpy(caseFile, "cases/case7.txt");
  printf("case 7: R$ %.3f\n", get_profit(caseFile));
  time = clock() - time;
  printf("execution time was: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);
  
  return 0;
}