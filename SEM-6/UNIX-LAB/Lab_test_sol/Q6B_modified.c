#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int file, n;
    char buffer[25];

    file = open("test.txt", O_RDONLY);

    read(file, buffer, 20); // 1) 20 bytes
    write(1, buffer, 20);
    printf("\n");

    lseek(file, 10, SEEK_SET); // 2) 20 char after 10th
    read(file, buffer, 20);
    write(1, buffer, 20);
    printf("\n");

    lseek(file, 10, SEEK_CUR); // 3) 20 char after 10th current offset
    read(file, buffer, 20);
    write(1, buffer, 20);
    printf("\n");

    n = lseek(file, 0, SEEK_END);

    printf("\n size: %d bytes \n", n); // 4) file size.
    return 0;
}

// run: gcc p1.c
// create test.txt with 100 char text.
// run: ./a.out