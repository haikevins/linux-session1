#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_function(void* arg) {
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;
    int result;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    result = pthread_create(&thread, &attr, thread_function, NULL);
    if (result != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    pthread_attr_destroy(&attr);
    // No need to join the thread as it's detached

    sleep(1); // Give detached thread time to finish
    return 0;
}

