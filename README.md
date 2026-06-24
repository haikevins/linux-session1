## Nội dung

| #  | Topic                                 | Nội dung chính                                                                                | Thực hành                                                                                                 |
| -- | ------------------------------------- | --------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| 1  | **Basic CMD**                         | Giới thiệu giao diện dòng lệnh, một số lệnh cơ bản, so sánh CLI với GUI                       | Thực hiện lệnh trong terminal, dùng pipeline, viết bash script đơn giản                                   |
| 2  | **File System**                       | Cấu trúc cây thư mục `/`, các loại file, phân quyền, inode, block                             | Dùng `ls -l`, `stat`, `file`, tạo/sửa/xóa file, dùng `chmod`, `chown`, `umask`, `mount`, `df`, `du`       |
| 3  | **Đọc ghi dữ liệu trong file**        | Khái niệm file trong Linux, file descriptor, `open`, `read`, `write`, `lseek`, `close`        | Viết chương trình C đọc/ghi file và thao tác nâng cao                                                     |
| 4  | **Quản lý hệ thống file trong Linux** | Thuộc tính file, hardlink, symbolic link, device file                                         | Viết chương trình C đọc/ghi thuộc tính file, tìm kiếm file, tạo hardlink/symlink                          |
| 5  | **Giới thiệu về process**             | Chương trình, tiến trình, không gian bộ nhớ, tài nguyên, thuộc tính và vòng đời process       | Viết chương trình C lấy thông tin process                                                                 |
| 6  | **Thông số môi trường của process**   | Môi trường hoạt động của process, `main`, terminate value, tham số truyền vào, shared library | Viết chương trình C thao tác với biến môi trường                                                          |
| 7  | **Luồng điều khiển process**          | Khởi tạo/terminate process, process cha/con, `fork`, `wait`, `exit`, `exec`, `system`, `nice` | Tạo process con, tương tác với process, lập lịch và chọn core                                             |
| 8  | **Signal**                            | Khái niệm signal, gửi/nhận signal, signal table, `sigset`, `sigaction`, `kill`                | Viết chương trình gửi/nhận signal, chặn Ctrl + C                                                          |
| 9  | **Multi-thread**                      | Thread, multi-thread, khởi tạo thread, phân biệt multi-core và multi-thread                   | Viết chương trình nhân ma trận, so sánh thời gian có/không dùng multi-thread                              |
| 10 | **Đồng bộ giữa các thread**           | Race condition, xung đột dữ liệu, mutex, semaphore, condition variable, barrier               | Viết chương trình nhiều thread dùng chung tài nguyên và đồng bộ bằng mutex/semaphore                      |
| 11 | **Daemon process**                    | Tiến trình chạy ẩn, tính chất daemon, standard input/output của daemon                        | Viết daemon lấy thông tin login user và tự động start khi boot                                            |
| 12 | **IPC**                               | Inter-Process Communication, Pipe, FIFO, shared memory, thư viện hỗ trợ IPC                   | Lập trình mô hình client-server giao tiếp bằng IPC                                                        |
| 13 | **Socket cơ bản**                     | Khái niệm socket, quy trình lập trình socket, `socket`, `bind`, `setsockopt`, `listen`        | Viết 2 chương trình C giao tiếp qua socket                                                                |
| 14 | **Socket nâng cao**                   | Định danh thiết bị trong LAN, địa chỉ IP/MAC, gửi nhận và phân luồng gói tin                  | Viết chương trình chat bằng C trong mạng LAN                                                              |
| 15 | **Toolchain**                         | Native Compiler, Cross Compiler, compiler, assembler, linker, debugger                        | Biên dịch C bằng cross compiler, so sánh binary bằng `file` hoặc `readelf`                                |
| 16 | **Dynamic / Static Library**          | Thư viện tĩnh `.a`, thư viện động `.so`, linking compile-time/runtime, ưu nhược điểm          | Viết thư viện `.a`, `.so`, gọi hàm từ chương trình chính, link bằng `gcc`                                 |
| 17 | **Makefile**                          | Target, dependency, command, biến trong Makefile, rule build nhiều file C                     | Viết Makefile, tách compile/link, dùng biến, thêm rule `clean`                                            |
| 18 | **CMake**                             | CMake, khác biệt với Makefile, `CMakeLists.txt`, target, include path, source files, library  | Viết `CMakeLists.txt`, build bằng `cmake` và `make`, dùng `target_link_libraries`, tạo build folder riêng |

## Cấu trúc repo

├── notes
│   ├── topic-01
│   ├── topic-02
│   ├── topic-03
│   │   └── systemcalls
│   ├── topic-04
│   ├── topic-05
│   ├── topic-06
│   ├── topic-07
│   ├── topic-08
│   ├── topic-09
│   ├── topic-10
│   ├── topic-11
│   ├── topic-12
│   ├── topic-13
│   ├── topic-14
│   ├── topic-15
│   ├── topic-16
│   ├── topic-17
│   └── topic-18
└── practices
    ├── topic-01
    ├── topic-02
    │   └── mydir
    │       └── dir1
    ├── topic-03
    │   ├── close
    │   ├── create
    │   ├── dup
    │   ├── exercise
    │   │   ├── cat
    │   │   └── copy
    │   ├── lseek
    │   ├── open
    │   ├── read
    │   └── write
    ├── topic-04
    │   ├── filelink
    │   └── stat
    ├── topic-05
    │   ├── fork
    │   └── get_process_info
    ├── topic-06
    ├── topic-07
    │   ├── execl
    │   ├── exercise
    │   │   ├── exercise1
    │   │   ├── exercise2
    │   │   └── exercise3
    │   ├── exit
    │   ├── fork
    │   ├── program_life_cycle
    │   └── wait
    ├── topic-08
    │   ├── exercise1
    │   └── exercise2
    ├── topic-09
    │   ├── exercise
    │   │   ├── exercise1
    │   │   └── exercise2
    │   ├── thread_cancel
    │   ├── thread_condition
    │   ├── thread_create
    │   ├── thread_detached
    │   ├── thread_key
    │   └── thread_mutexes
    ├── topic-10
    │   ├── thread_mutex
    │   └── thread_sem
    ├── topic-11
    │   └── login_daemon
    ├── topic-12
    │   └── client_sever
    ├── topic-13
    ├── topic-14
    ├── topic-15
    └── topic-16
