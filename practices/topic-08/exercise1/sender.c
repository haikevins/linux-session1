#include <stdio.h>
#include <signal.h>

// code gửi signal

int main() {
    int pid, choice;

    printf("Nhap PID: ");
    scanf("%d", &pid);

    printf("Chon signal:\n");
    printf("1. SIGINT\n");
    printf("2. SIGUSR1\n");
    printf("Lua chon: ");
    scanf("%d", &choice);

    if (choice == 1) {
        kill(pid, SIGINT);
    } else if (choice == 2) {
        kill(pid, SIGUSR1);
    } else {
        printf("Lua chon khong hop le\n");
    }

    return 0;
}
