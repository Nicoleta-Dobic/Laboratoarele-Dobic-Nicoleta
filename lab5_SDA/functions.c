#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void init_array(IntArray* arr, int size) {
    arr->size = size;
    arr->data = (int*)malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr->data[i] = rand() % 100000;
    }
}

void print_array(const IntArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void free_array(IntArray* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
}

void selection_sort(IntArray* arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arr->size; j++) {
            if (arr->data[j] < arr->data[min])
                min = j;
        }
        int tmp = arr->data[i];
        arr->data[i] = arr->data[min];
        arr->data[min] = tmp;
    }
}

void heapify(int* data, int size, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < size && data[l] > data[largest])
        largest = l;
    if (r < size && data[r] > data[largest])
        largest = r;
    if (largest != i) {
        int temp = data[i];
        data[i] = data[largest];
        data[largest] = temp;
        heapify(data, size, largest);
    }
}

void heap_sort(IntArray* arr) {
    int n = arr->size;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr->data, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr->data[0];
        arr->data[0] = arr->data[i];
        arr->data[i] = temp;
        heapify(arr->data, i, 0);
    }
}

int linear_search(const IntArray* arr, int value) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == value)
            return i;
    }
    return -1;
}

int binary_search(const IntArray* arr, int value) {
    int l = 0, r = arr->size - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr->data[m] == value)
            return m;
        else if (arr->data[m] < value)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

void fibonacci(unsigned long long n) {
    unsigned long long* fib = (unsigned long long*)malloc((n + 2) * sizeof(unsigned long long));
    fib[0] = 0;
    fib[1] = 1;
    for (unsigned long long i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("fib(%llu) = %llu\n", n, fib[n]);
    free(fib);
}

double get_time(void (*func)(IntArray*), IntArray* arr) {
    clock_t start = clock();
    func(arr);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}
