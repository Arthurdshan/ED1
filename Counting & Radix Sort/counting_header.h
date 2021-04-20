#pragma once

//creating struct type as Info
typedef struct info{
    int data;
    int key;
}Info;

//functions prototypes
int get_max_element(Info *vector, int size);
void counting_sort(Info *vector, int size);
