#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fs;
    lstat("sample.txt", &fs);

    printf("Mode: \t\t\t%o\n", fs.st_mode & 07777);
    printf("Size: \t\t\t%lu bytes\n", fs.st_size);
    printf("Number of Links: \t%lu\n", fs.st_nlink);
    printf("Inode: \t\t\t%lu\n", fs.st_ino); 
    printf("Block Size: \t\t%lu\n", fs.st_blksize);

    return 0;
}

// gedit p1.c
// gedit sample.txt ("HelloWorld!")
// gcc p1.c
// ./a.out