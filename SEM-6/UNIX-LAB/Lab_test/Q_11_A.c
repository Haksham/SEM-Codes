#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {

    int fd1 = open("example.txt", O_WRONLY);
    int fd2 = dup(fd1);
    int fd3=dup2(fd1, 10);

    write(fd1, "Writing via fd1 \n", 16);
    write(fd2, "Writing via fd2 \n", 16);
    write(fd3, "Writing via fd3 (dup2)\n", 50);
    return 0;
}
// run: gcc p1.c
// make an example.txt file
// run: ./a.out
// run: cat example.txt