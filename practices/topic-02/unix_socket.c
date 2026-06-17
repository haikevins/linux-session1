#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int sockfd;
    struct sockaddr_un addr;

    // Tạo socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Xóa file cũ nếu tồn tại
    unlink("mysocket");

    // Cấu hình địa chỉ
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, "mysocket");

    // Bind socket với file
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        exit(1);
    }

    printf("Socket file 'mysocket' created.\n");
    pause();  // Giữ chương trình chạy để bạn kiểm tra

    close(sockfd);
    return 0;
}
