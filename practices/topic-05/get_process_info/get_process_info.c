#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char pid[20];
    printf("Nhập PID của process: ");
    scanf("%s", pid);

    char path[100];
    snprintf(path, sizeof(path), "/proc/%s/status", pid);

    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Không thể mở file /proc/[pid]/status");
        return 1;
    }

    char line[256];
    printf("\nThông tin về process PID %s:\n", pid);
    while (fgets(line, sizeof(line), file)) {
        // In các dòng quan trọng
        if (strncmp(line, "Name:", 5) == 0 ||
            strncmp(line, "State:", 6) == 0 ||
            strncmp(line, "Pid:", 4) == 0 ||
            strncmp(line, "PPid:", 5) == 0 ||
            strncmp(line, "Uid:", 4) == 0 ||
            strncmp(line, "Gid:", 4) == 0) {
            printf("%s", line);
        }
    }

    fclose(file);
    return 0;
}
