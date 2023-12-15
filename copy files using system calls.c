#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

void copyFile(const char *sourcePath, const char *destinationPath) {
    int sourceFile, destinationFile;
    char buffer[BUF_SIZE];
    ssize_t bytesRead, bytesWritten;

    // Open source file for reading
    sourceFile = open(sourcePath, O_RDONLY);
    if (sourceFile == -1) {
        perror("open source file");
        exit(EXIT_FAILURE);
    }

    // Open destination file for writing (create if it doesn't exist)
    destinationFile = open(destinationPath, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (destinationFile == -1) {
        perror("open destination file");
        close(sourceFile);
        exit(EXIT_FAILURE);
    }

    // Copy file content
    while ((bytesRead = read(sourceFile, buffer, BUF_SIZE)) > 0) {
        bytesWritten = write(destinationFile, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("write");
            close(sourceFile);
            close(destinationFile);
            exit(EXIT_FAILURE);
        }
    }

    // Close files
    close(sourceFile);
    close(destinationFile);

    printf("File copied successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copyFile(argv[1], argv[2]);

    return 0;
}
