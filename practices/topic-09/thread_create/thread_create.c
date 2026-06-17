#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>

void* thread_function(void* arg) {
    printf("Thread ID: %lu\n", pthread_self());
    printf("Kernel TID: %d\n", syscall(SYS_gettid));
    return NULL;
}

int main() {
    pthread_t thread;
    int result;

    result = pthread_create(&thread, NULL, thread_function, NULL);
    if (result != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread, NULL);
    return 0;
}
