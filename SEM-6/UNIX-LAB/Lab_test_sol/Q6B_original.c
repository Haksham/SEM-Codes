#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int file = 0, n;
    char buffer[25];

    if ((file = open("test.txt", O_RDONLY)) < 0)
        printf("file open error\n");

    if (read(file, buffer, 20) != 20)
        printf("file read operation failed\n");
    else
        write(STDOUT_FILENO, buffer, 20);
    printf("\n");

    if (lseek(file, 10, SEEK_SET) < 0)
        printf("lseek operation to beginning of file failed\n");

    if (read(file, buffer, 20) != 20)
        printf("file read operation failed\n");
    else
        write(STDOUT_FILENO, buffer, 20);
    printf("\n");

    if (lseek(file, 10, SEEK_CUR) < 0)
        printf("lseek operation to current position failed\n");

    if (read(file, buffer, 20) != 20)
        printf("file read operation failed\n");
    else
        write(STDOUT_FILENO, buffer, 20);
    printf("\n");

    if ((n = lseek(file, 0, SEEK_END)) < 0)
        printf("lseek operation to end of file failed\n");

    printf("size of file is %d bytes\n", n);

    close(file);
    return 0;
}

// run: gcc p1.c
// create test.txt with 100 char text.
// run: ./a.out