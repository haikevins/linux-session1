#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
	int fd_file;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	/* kiểm tra tham số */
	if (argc != 2) {
		fprintf(stderr, "Usage: %s my_file\n", argv[0]);
		exit(1);
	}
	
	/* mở file */
	fd_file = open(argv[1], O_RDONLY | O_CREAT, 0644);
	if (fd_file < 0) {
		perror("Error create or open file");
		return 1;
	}
	
	/* đọc và ghi từng khối dữ liệu ra terminal */
	while ((bytes_read = read(fd_file, buffer, BUFFER_SIZE)) > 0) {
		
		bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

		if (bytes_written != bytes_read) {
			perror("Write error");
			close(fd_file);
			exit(1);
		}		
	}

	if (bytes_read < 0) {
		perror("Error read");
	}

	close(fd_file);

	return 0;
}
