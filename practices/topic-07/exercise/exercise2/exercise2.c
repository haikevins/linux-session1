#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>

// Viết một chương trình C để lập lịch và chọn core cho process.

int main() {
    cpu_set_t set;

    CPU_ZERO(&set);     // clear
    CPU_SET(0, &set);   // chọn core 0

    if (sched_setaffinity(0, sizeof(set), &set) == -1) {
        perror("sched_setaffinity");
        return 1;
    }

    printf("Running on CPU 0\n");

    while (1) {
        // loop để giữ process chạy
    }

    return 0;
}
