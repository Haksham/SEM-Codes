#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    umask(077); // Set umask to 077 (no permissions for group and others
    open("file1.txt", O_CREAT | O_WRONLY, 0666); // Create a file with default permissions 0666 (rw-rw-rw-)
    chmod("file1.txt", 0644); // Change file permissions to 644 (rw-r--r--)
    return 0;
}

// run: gcc p1.c
// run: ./a.out file1
// file1 should be non existent.
// run: ls -l file1

// or can do both chmod and umask as separate codes files and then show permission by : ls -l file1.
// note: no error to be displayed.