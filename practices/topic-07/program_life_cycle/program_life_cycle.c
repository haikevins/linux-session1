#include <stdio.h>
#include <stdlib.h>

// exit handler 1
void cleanup1(void) {
    printf("Cleanup 1: giải phóng tài nguyên A\n");
}

// exit handler 2
void cleanup2(void) {
    printf("Cleanup 2: giải phóng tài nguyên B\n");
}

int main() {
    printf("Bắt đầu chương trình (main)\n");

    // đăng ký các hàm sẽ chạy khi chương trình kết thúc
    atexit(cleanup1);
    atexit(cleanup2);

    printf("Đang xử lý trong main...\n");

    // kết thúc chương trình
    exit(0);

    // dòng này sẽ không bao giờ chạy
    printf("Dòng này không được in\n");
    return 0;
}
