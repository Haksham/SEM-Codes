#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    const char *filename = argv[1];
    umask(022);

    open(filename, O_CREAT | O_WRONLY, 0777);
    printf("File created.");
    
    chmod(filename, 0640);
    printf("Permissions changed to 0640 ");

    return 0;
}

// run: gcc p1.c
// run: ./a.out file1
// file1 should be non existent.
// run: ls -l file1

// or can do both chmod and umask as separate codes files and then show permission by : ls -l file1.
// note: no error to be displayed.