#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    IntArray arr;
    int option, size, value;

    while (1) {
        printf("\nMeniu:\n");
        printf("1. Inițializare tablou\n");
        printf("2. Afișare tablou\n");
        printf("3. Sortare (Selection Sort)\n");
        printf("4. Sortare (Heap Sort)\n");
        printf("5. Căutare Lineară\n");
        printf("6. Căutare Binara\n");
        printf("7. Fibonacci\n");
        printf("8. Eliberare memorie\n");
        printf("0. Ieșire\n");
        printf("Opțiune: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Dimensiune: ");
            scanf("%d", &size);
            init_array(&arr, size);
            break;
            case 2:
                print_array(&arr);
            break;
            case 3:
                printf("Timp sortare: %.5f sec\n", get_time(selection_sort, &arr));
            break;
            case 4:
                printf("Timp sortare: %.5f sec\n", get_time(heap_sort, &arr));
            break;
            case 5:
                printf("Valoare: ");
            scanf("%d", &value);
            printf("Poziție: %d\n", linear_search(&arr, value));
            break;
            case 6:
                printf("Valoare: ");
            scanf("%d", &value);
            printf("Poziție: %d\n", binary_search(&arr, value));
            break;
            case 7:
                printf("Poziția N: ");
            unsigned long long n;
            scanf("%llu", &n);
            fibonacci(n);
            break;
            case 8:
                free_array(&arr);
            break;
            case 0:
                free_array(&arr);
            return 0;
        }
    }
}
