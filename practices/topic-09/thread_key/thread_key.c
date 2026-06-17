#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_key_t key; // key dung de luu du lieu rieng cho moi thread

// ham destructor duoc goi khi thread ket thuc
void destructor(void* arg) {
    free(arg); // giai phong bo nho da cap phat
    printf("Thread-specific data freed\n");
}

void* thread_function(void* arg) {
    unsigned long* thread_data = malloc(sizeof(unsigned long)); // cap phat bo nho rieng cho thread
    *thread_data = (unsigned long)pthread_self(); // gan gia tri ID thread vao bien
    pthread_setspecific(key, thread_data); // luu du lieu nay vao key (rieng cho thread hien tai)
        
    unsigned long* value = pthread_getspecific(key); // lay du lieu tu key

    // in ra ID thread va du lieu rieng cua no
    printf("Thread ID: %lu\n",  *value);

    return NULL; // thread ket thuc
}

int main() {
    pthread_t thread;
    
    // tao key va gan destructor de tu dong giai phong bo nho khi thread ket thuc
    pthread_key_create(&key, destructor);

    // tao thread moi
    pthread_create(&thread, NULL, thread_function, NULL);

    // doi thread chay xong
    pthread_join(thread, NULL);

    // xoa key (khong anh huong den du lieu da free)
    pthread_key_delete(key);

    return 0;
}
