#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// code nhận signal

void handle_signal(int sig) {
    if (sig == SIGINT)
        printf("Nhan duoc SIGINT (Ctrl+C)\n");
    else if (sig == SIGUSR1)
        printf("Nhan duoc SIGUSR1\n");
}

int main() {
    printf("PID cua process: %d\n", getpid());

    signal(SIGINT, handle_signal);
    signal(SIGUSR1, handle_signal);

    while (1) {
        pause(); // chờ signal
    }

    return 0;
}
