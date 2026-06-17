#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

void* thread_function(void* arg) {
    while (1) {
        printf("Thread ID: %lu\n", pthread_self());
        sleep(1); // <-- cancellation point
    }
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

    sleep(3); // Let the thread run for a while
    pthread_cancel(thread);

    pthread_join(thread, NULL); // Clean up the canceled thread
    return 0;
}

