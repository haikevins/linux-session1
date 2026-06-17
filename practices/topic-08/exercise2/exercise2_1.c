#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Bắt signal nhưng không làm gì

void ignore_sigint(int sig) {
    printf("Ban vua nhan Ctrl+C nhung bi chan!\n");
}

int main() {
    signal(SIGINT, ignore_sigint);

    while (1) {
        printf("Dang chay...\n");
        sleep(1);
    }

    return 0;
}
