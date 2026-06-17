#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Viết một chương trình C để tạo ra một process con và tương tác với nó.

// Parent ──write──▶ pipe ──read──▶ Child

int main() {
    int fd[2];
    pid_t pid;
    char buffer[100];

    // tạo pipe
    pipe(fd);

    pid = fork();

    if (pid == 0) {
        // Child
        close(fd[1]); // đóng đầu ghi

        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        close(fd[0]);
    } else {
        // Parent
        close(fd[0]); // đóng đầu đọc

        char msg[] = "Hello from parent!";
        write(fd[1], msg, strlen(msg) + 1);

        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
