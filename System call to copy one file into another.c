#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }
    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) 
    {
        perror("Error opening source file");
        exit(1);
    }
    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd == -1) 
    {
        perror("Error opening destination file");
        close(source_fd);
        exit(1);
    }
    char buffer[4096];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) 
    {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            exit(1);
        }
    }
    if (bytes_read == -1) {
        perror("Error reading from source file");
        close(source_fd);
        close(dest_fd);
        exit(1);
    }
    close(source_fd);
    close(dest_fd);
    printf("File copied successfully!\n");
}
