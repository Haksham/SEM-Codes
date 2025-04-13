// Write a C program to display the file content in reverse order using lseek system call.

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int src, dest, n,i;
    char buf;
    int filesize;

    if (argc != 3) {
        fprintf(stderr, "usage %s <src> <dest>\n", argv[0]);
        exit(-1);
    }

    if ((src = open(argv[1], O_RDONLY)) < 0) {
        fprintf(stderr, "can't open src\n");
        exit(-1);
    }

    if ((dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
        fprintf(stderr, "can't create dest\n");
        exit(-1);
    }

    filesize = lseek(src, (off_t)0, SEEK_END);
    printf("src file size is %d\n", filesize);

    for (i = filesize - 1; i >= 0; i--) {
        lseek(src, (off_t)i, SEEK_SET);
        if ((n = read(src, &buf, 1)) != 1) {
            fprintf(stderr, "can't read 1 byte\n");
            exit(-1);
        }
        if ((n = write(dest, &buf, 1)) != 1) {
            fprintf(stderr, "can't write 1 byte\n");
            exit(-1);
        }
    }

    write(STDOUT_FILENO, "DONE\n", 5);
    close(src);
    close(dest);
    return 0;
}

// make src.txt with some text and dest.txt as empty
// run: gcc p1.c
// ./a.out src.txt dest.txt