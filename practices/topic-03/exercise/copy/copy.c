#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    int fd_src, fd_dest;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    /* kiểm tra tham số */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file dest_file\n", argv[0]);
        exit(1);
    }

    /* mở file nguồn */
    fd_src = open(argv[1], O_RDONLY);
    if (fd_src < 0) {
        perror("Cannot open source file");
        exit(1);
    }

    /* mở / tạo file đích */
    fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest < 0) {
        perror("Cannot open destination file");
        close(fd_src);
        exit(1);
    }

    /* đọc và ghi từng khối dữ liệu */
    while ((bytes_read = read(fd_src, buffer, BUFFER_SIZE)) > 0) {

        bytes_written = write(fd_dest, buffer, bytes_read);

        if (bytes_written != bytes_read) {
            perror("Write error");
            close(fd_src);
            close(fd_dest);
            exit(1);
        }
    }

    if (bytes_read < 0) {
        perror("Read error");
    }

    /* đóng file */
    close(fd_src);
    close(fd_dest);

    return 0;
}
