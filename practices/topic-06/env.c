#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 1. Lấy một biến môi trường
    char *path = getenv("PATH"); // lấy biến PATH
    if (path != NULL) {
        printf("Giá trị của PATH: %s\n", path);
    } else {
        printf("PATH không tồn tại!\n");
    }

    // 2. Thiết lập một biến môi trường mới
    // Tham số: tên biến, giá trị, overwrite (1 = ghi đè nếu đã tồn tại)
    if (setenv("MY_VAR", "Hello_World", 1) == 0) {
        printf("Đã tạo/ghi đè biến MY_VAR\n");
    } else {
        perror("setenv failed");
    }

    // 3. Lấy giá trị biến vừa tạo
    char *my_var = getenv("MY_VAR");
    printf("MY_VAR = %s\n", my_var);

    // 4. Xóa biến môi trường
    if (unsetenv("MY_VAR") == 0) {
        printf("Đã xóa biến MY_VAR\n");
    } else {
        perror("unsetenv failed");
    }

    // 5. Thử lấy biến vừa xóa
    my_var = getenv("MY_VAR");
    if (my_var == NULL)
        printf("MY_VAR không còn tồn tại\n");

    return 0;
}
