/* 
gcc -fopenmp -O2 exercise02.c -o exercise02 && ./exercise02
*/

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define M 40
#define NUM_THREADS 4

int fibonacci(int n) {
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int arr[M];
    int results[M];
    int counts[NUM_THREADS] = {0};
    
    // Initialize array with values
    for (int i = 0; i < M; i++) {
        arr[i] = 30 + (i % 6); // Values between 30-35
    }

    // Policy 1: static
    double start = omp_get_wtime();
    #pragma omp parallel for schedule(static) num_threads(NUM_THREADS)
    for (int i = 0; i < M; i++) {
        int tid = omp_get_thread_num();
        #pragma omp atomic
        counts[tid]++;
        results[i] = fibonacci(arr[i]);
    }
    double end = omp_get_wtime();
    printf("Static: Tiempo = %.6f segundos\n", end - start);
    printf("Participacion hilos: ");
    for (int i = 0; i < NUM_THREADS; i++) printf("%d ", counts[i]);
    printf("\n\n");

    // Reset counts
    for (int i = 0; i < NUM_THREADS; i++) counts[i] = 0;

    // Policy 2: dynamic,1
    start = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic, 1) num_threads(NUM_THREADS)
    for (int i = 0; i < M; i++) {
        int tid = omp_get_thread_num();
        #pragma omp atomic
        counts[tid]++;
        results[i] = fibonacci(arr[i]);
    }
    end = omp_get_wtime();
    printf("Dynamic,1: Tiempo = %.6f segundos\n", end - start);
    printf("Participacion hilos: ");
    for (int i = 0; i < NUM_THREADS; i++) printf("%d ", counts[i]);
    printf("\n\n");

    // Reset counts
    for (int i = 0; i < NUM_THREADS; i++) counts[i] = 0;

    // Policy 3: guided,1
    start = omp_get_wtime();
    #pragma omp parallel for schedule(guided, 1) num_threads(NUM_THREADS)
    for (int i = 0; i < M; i++) {
        int tid = omp_get_thread_num();
        #pragma omp atomic
        counts[tid]++;
        results[i] = fibonacci(arr[i]);
    }
    end = omp_get_wtime();
    printf("Guided,1: Tiempo = %.6f segundos\n", end - start);
    printf("Participacion hilos: ");
    for (int i = 0; i < NUM_THREADS; i++) printf("%d ", counts[i]);
    printf("\n");

    return 0;
}