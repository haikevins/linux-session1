#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int shared_resource = 0;

void* thread_function(void* arg) {
    pthread_mutex_lock(&mutex);
    shared_resource++;
    printf("Thread ID: %lu, Shared Resource: %d\n", pthread_self(), shared_resource);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[5];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
