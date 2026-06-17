// server.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_CS "fifo_cs"
#define FIFO_SC "fifo_sc"
#define MAX_BUF 1024

int main() {
    int fd_cs, fd_sc;
    char buffer[MAX_BUF];

    // Tạo FIFO
    mkfifo(FIFO_CS, 0666);
    mkfifo(FIFO_SC, 0666);

    printf("Server is running...\n");

    while (1) {
        // mở FIFO đọc từ client
        fd_cs = open(FIFO_CS, O_RDONLY);
        read(fd_cs, buffer, MAX_BUF);

        printf("Received from client: %s\n", buffer);

        // xử lý: đổi thành chữ hoa
        for (int i = 0; buffer[i]; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z')
                buffer[i] -= 32;
        }

        close(fd_cs);

        // gửi lại cho client
        fd_sc = open(FIFO_SC, O_WRONLY);
        write(fd_sc, buffer, strlen(buffer) + 1);
        close(fd_sc);
    }

    return 0;
}
