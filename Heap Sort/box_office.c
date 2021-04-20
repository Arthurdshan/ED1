#include <stdio.h>
#include <stdlib.h>
#include "box_office.h"
#include "heap_sort.h"
#include "priority_queue.h"

float get_profit(char *archive){
  FILE *file = fopen(archive, "r");   
  if(file == NULL) return -1;

  int number_of_rows, number_of_people;
  
  fscanf(file,"%d", &number_of_rows);
  if(number_of_rows > 1000 || number_of_rows < 1) return -1;
  
  fscanf(file,"%d", &number_of_people);
  if(number_of_people > 1000 || number_of_people < 1) return -1;
  
  int *seats_per_row = create_queue(number_of_rows);
  
  for(int i = 0; i < number_of_rows; i++) fscanf(file,"%d", &seats_per_row[i]);
  
  build_min_heap(seats_per_row, number_of_rows);

  float x = calculate_profit(seats_per_row, number_of_rows, number_of_people);

  free(seats_per_row);

  return x;
};

float calculate_profit(int *seats_per_row, int number_of_rows, int number_of_people){
    float profit = 0;
    while(number_of_people > 0){
      int least_seats_row = get_first_element(seats_per_row, number_of_rows);
      number_of_rows = remove_min_element(seats_per_row, number_of_rows);
      while(least_seats_row > 0 && number_of_people > 0){
        profit += 100 + (float)100 / least_seats_row;
        least_seats_row--;
        number_of_people--;
      }
    }
  return profit;
};