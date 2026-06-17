#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    ssize_t sz;

    fd = open("foo.txt", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    sz = write(fd, "hello geeks\n", strlen("hello geeks\n"));

    printf("called write(%d, \"hello geeks\\n\", %zu). "
           "It returned %zd\n",
           fd, strlen("hello geeks\n"), sz);

    close(fd);

    return 0;
}
