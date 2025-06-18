#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"


void init_array(IntArray* arr, int size);
void print_array(const IntArray* arr);
void free_array(IntArray* arr);

void selection_sort(IntArray* arr);
void heap_sort(IntArray* arr);

int linear_search(const IntArray* arr, int value);
int binary_search(const IntArray* arr, int value);

void fibonacci(unsigned long long n);

double get_time(void (*func)(IntArray*), IntArray* arr);

#endif
