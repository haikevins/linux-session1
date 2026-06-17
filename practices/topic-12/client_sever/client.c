// client.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_CS "fifo_cs"
#define FIFO_SC "fifo_sc"
#define MAX_BUF 1024

int main() {
    int fd_cs, fd_sc;
    char buffer[MAX_BUF];

    while (1) {
        printf("Enter message: ");
        fgets(buffer, MAX_BUF, stdin);

        // gửi cho server
        fd_cs = open(FIFO_CS, O_WRONLY);
        write(fd_cs, buffer, strlen(buffer) + 1);
        close(fd_cs);

        // nhận phản hồi
        fd_sc = open(FIFO_SC, O_RDONLY);
        read(fd_sc, buffer, MAX_BUF);

        printf("Server replied: %s\n", buffer);
        close(fd_sc);
    }

    return 0;
}
