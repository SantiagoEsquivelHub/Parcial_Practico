/* 
gcc -fopenmp -O0 -g -o exercise01 exercise01.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 4096
#define MAX_SIZE (N * N)

void sequential_row_traversal(int *arr) {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            arr[i * N + k] += 3;
        }
    }
}

void parallel_row_traversal(int *arr, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            arr[i * N + k] += 3;
        }
    }
}

void sequential_col_traversal(int *arr) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            arr[i * N + k] += 3;
        }
    }
}

void parallel_col_traversal(int *arr, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            arr[i * N + k] += 3;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <version>\n", argv[0]);
        printf("Versiones:\n");
        printf("1 - Recorrido por filas secuencial\n");
        printf("2 - Recorrido por filas paralelo\n");
        printf("3 - Recorrido por columnas secuencial\n");
        printf("4 - Recorrido por columnas paralelo\n");
        return 1;
    }

    int version = atoi(argv[1]);
    int *arr = (int*)malloc(MAX_SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Error: Falló la asignación de memoria\n");
        return 1;
    }

    // Initialize with random values
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    double start = omp_get_wtime();
    
    switch(version) {
        case 1:
            sequential_row_traversal(arr);
            break;
        case 2:
            parallel_row_traversal(arr, omp_get_max_threads());
            break;
        case 3:
            sequential_col_traversal(arr);
            break;
        case 4:
            parallel_col_traversal(arr, omp_get_max_threads());
            break;
        default:
            printf("Versión no válida\n");
            free(arr);
            return 1;
    }

    double end = omp_get_wtime();
    printf("Tiempo: %.6f segundos\n", end - start);
    fflush(stdout);

    free(arr);
    return 0;
}