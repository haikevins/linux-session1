#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) < 0) {
        perror("stat error");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Inode: %ld\n", fileStat.st_ino);
    printf("Links: %ld\n", fileStat.st_nlink);

    printf("Permission: %o\n", fileStat.st_mode & 0777);
    
    printf("Last access: %s", ctime(&fileStat.st_atime));
    printf("Last modified: %s", ctime(&fileStat.st_mtime));
    printf("Last status changed: %s", ctime(&fileStat.st_ctime));
    /* Ví dụ thay đổi quyền */
    printf("\nChanging permission to 644...\n");

    if (chmod(argv[1], 0644) == -1) {
        perror("chmod error");
        return 1;
    }

    printf("Permission changed!\n");

    return 0;
}
