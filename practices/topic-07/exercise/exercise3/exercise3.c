#include <sched.h>
#include <stdio.h>

// chọn scheduler policy

int main() {
    struct sched_param param;
    param.sched_priority = 10;

    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    while(1);
}
