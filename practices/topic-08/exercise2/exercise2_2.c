#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Chặn hoàn toàn bằng signal mask

int main() {
    sigset_t set;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    // block SIGINT
    sigprocmask(SIG_BLOCK, &set, NULL);

    while (1) {
        printf("SIGINT dang bi block...\n");
        sleep(1);
    }

    return 0;
}
