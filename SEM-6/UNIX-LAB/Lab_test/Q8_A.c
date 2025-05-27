#include <stdio.h>
#include <sys/stat.h>
#include<fcntl.h>

int main() {
    
    char filename[20];
    struct stat st;

    printf("Enter the filename: ");
    scanf("%s", filename);
    lstat(filename, &st);


    if (S_ISREG(st.st_mode))      printf("Regular file\n");
    else if (S_ISDIR(st.st_mode)) printf("Directory\n");
    else if (S_ISLNK(st.st_mode)) printf("Symbolic link\n");
    else if (S_ISCHR(st.st_mode)) printf("Character device\n");
    else if (S_ISBLK(st.st_mode)) printf("Block device\n");
    else if (S_ISFIFO(st.st_mode))printf("FIFO (named pipe)\n");
    else if (S_ISSOCK(st.st_mode))printf("Socket\n");
    else                          printf("Unknown file type\n");

    return 0;
}

// gedit p1.c
// gedit sample.txt ("HelloWorld!")
// gcc p1.c
// ./a.out

// Enter the filename: sample.txt