#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s directory filename\n", argv[0]);
        return 1;
    }

    DIR *d;
    struct dirent *dir;

    d = opendir(argv[1]);

    if (d == NULL) {
        perror("opendir error");
        return 1;
    }

    while ((dir = readdir(d)) != NULL) {

        if (strcmp(dir->d_name, argv[2]) == 0) {

            printf("Found file: %s\n", dir->d_name);

            char hardlink_name[] = "hardlink_file";
            char symlink_name[] = "symlink_file";

            if (link(argv[2], hardlink_name) == 0) {
                printf("Hard link created\n");
            } else {
                perror("link");
            }

            if (symlink(argv[2], symlink_name) == 0) {
                printf("Symbolic link created\n");
            } else {
                perror("symlink");
            }

            break;
        }
    }

    closedir(d);

    return 0;
}
