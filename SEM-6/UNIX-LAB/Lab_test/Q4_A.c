#include <stdio.h>
#include <unistd.h>

int main() {

    link("test.txt", "hardlink.txt");
    printf("Hard link created successfully.\n");

    symlink("test.txt", "softlink.txt");
    printf("Soft link created successfully.\n");

    return 0;
}

// gedit test.txt
// gcc p1.c
// ./a.out
// ls -l

// The output will show the creation of a hard link and a soft link to "test.txt".
// The hard link will be named "hardlink.txt" and the soft link will be named "softlink.txt".