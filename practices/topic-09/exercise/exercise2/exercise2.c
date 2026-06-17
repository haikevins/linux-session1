#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500
#define NUM_THREADS 4

int A[SIZE][SIZE];
int B[SIZE][SIZE];
int C[SIZE][SIZE];

typedef struct {
    int start_row;
    int end_row;
} ThreadData;

// ================= SINGLE THREAD =================
void multiply_single() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// ================= MULTI THREAD =================
void* multiply_thread(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return NULL;
}

void multiply_multi() {
    pthread_t threads[NUM_THREADS];
    ThreadData data[NUM_THREADS];

    int rows_per_thread = SIZE / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].start_row = i * rows_per_thread;
        data[i].end_row = (i == NUM_THREADS - 1) ? SIZE : (i + 1) * rows_per_thread;

        pthread_create(&threads[i], NULL, multiply_thread, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

// ================= INIT =================
void init_matrix() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
}

// ================= MAIN =================
int main() {
    struct timespec start, end;

    init_matrix();

    // SINGLE THREAD
    clock_gettime(CLOCK_MONOTONIC, &start);
    multiply_single();
    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_single = (end.tv_sec - start.tv_sec) +
                         (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Single thread time: %f seconds\n", time_single);

    // MULTI THREAD
    clock_gettime(CLOCK_MONOTONIC, &start);
    multiply_multi();
    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_multi = (end.tv_sec - start.tv_sec) +
                        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Multi thread time: %f seconds\n", time_multi);

    return 0;
}
