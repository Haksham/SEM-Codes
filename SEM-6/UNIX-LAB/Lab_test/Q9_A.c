#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    umask(022);
    open("demo.txt", O_CREAT | O_WRONLY);
    chmod("demo.txt", 0704);

    return 0;
}     

// gcc p1.c
// ./a.out
// run: ls -l demo.txt

// or can do both chmod and umask as separate codes files and then show permission by : ls -l file1.
// note: no error to be displayed.