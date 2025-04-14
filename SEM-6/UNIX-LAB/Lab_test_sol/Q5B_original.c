#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd1, fd2, fd3;

    fd1 = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd1 < 0) {
        perror("open");
        exit(1);
    }

    fd2 = dup(fd1);
    if (fd2 < 0) {
        perror("dup");
        exit(1);
    }

    fd3 = 10;
    if (dup2(fd1, fd3) < 0) {
        perror("dup2");
        exit(1);
    }

    write(fd1, "Writing via fd1\n", 16);
    write(fd2, "Writing via fd2\n", 16);
    write(fd3, "Writing via fd3 (dup2)\n", 23);

    close(fd1);
    close(fd2);
    close(fd3);

    printf("Check 'example.txt' for the results.\n");

    return 0;
}

// run: gcc p1.c
// make an example.txt file
// run: ./a.out
// run: cat example.txt