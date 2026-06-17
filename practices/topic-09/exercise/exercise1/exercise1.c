#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// su dung key de lam moi truong luu tru du lieu rieng cho moi thread

pthread_key_t key;

// destructor: giai phong bo nho khi thread ket thuc
void destructor(void* arg) {
    free(arg);
}

// ham log (co the duoc goi o bat ky dau)
void log_message(const char* message) {
    char* thread_name = (char*)pthread_getspecific(key);
    printf("[%s] %s\n", thread_name, message);
}

// ham thread
void* thread_function(void* arg) {
    char* name = (char*)arg;

    // cap phat va luu ten thread vao key
    char* thread_name = malloc(strlen(name) + 1);
    strcpy(thread_name, name);
    pthread_setspecific(key, thread_name);

    // goi ham log (khong can truyen name)
    log_message("Thread started");
    sleep(1);
    log_message("Thread doing work");
    sleep(1);
    log_message("Thread finished");

    return NULL;
}

int main() {
    pthread_t t1, t2;

    // tao key
    pthread_key_create(&key, destructor);

    // tao 2 thread voi ten khac nhau
    pthread_create(&t1, NULL, thread_function, "Thread-A");
    pthread_create(&t2, NULL, thread_function, "Thread-B");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_key_delete(key);
    return 0;
}
