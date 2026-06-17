#include <stdlib.h>
#include <unistd.h>
#include<stdio.h> 
#include<fcntl.h> 

int main() {

    // Assume that foo.txt is already created 
    int fd1 = open("foo.txt", O_RDONLY, 0); 
    close(fd1); 

    // assume that baz.tzt is already created 
    int fd2 = open("baz.txt", O_RDONLY, 0); 

    printf("fd2 = % d\n", fd2); 
    exit(0); 
}
