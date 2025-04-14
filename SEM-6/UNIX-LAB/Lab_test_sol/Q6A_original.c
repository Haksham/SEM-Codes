#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    const char *filename = argv[1];

    umask(022);

    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    close(fd);

    printf("File '%s' created. Check permissions using: ls -l \n", filename);
    
    if (chmod(filename, 0640) < 0) {
        perror("chmod");
        exit(1);
    }

    printf("Permissions changed to 0640. Check again using: ls -l %s\n", filename);

    return 0;
}

// run: gcc p1.c
// run: ./a.out file1
// file1 should be non existent.
// run: ls -l file1

// or can do both chmod and umask as separate codes files and then show permission by : ls -l file1.