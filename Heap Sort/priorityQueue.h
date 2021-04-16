#pragma once 

int* create_queue(int size);
int get_first_element(int* priority_queue, int size);
int remove_max_element(int* priority_queue, int size);
int insert_new_element(int* priority_queue, int size, int new_element);
int remove_min_element(int* priority_queue, int size);
int insert_new_min_element(int* priority_queue, int size, int new_element);
