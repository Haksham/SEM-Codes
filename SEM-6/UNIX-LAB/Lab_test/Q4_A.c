#include <stdio.h>
#include <unistd.h>

int main() {

    link("test.txt", "hardlink.txt");
    printf("Hard link created successfully.\n");

    symlink("test.txt", "softlink.txt");
    printf("Soft link created successfully.\n");

    return 0;
}

// run: gcc p1.c

// create t1.txt with some text
// Hard link-run : ./a.out t1.txt t2.txt

// remove t2.txt ,run: rm t2.txt
// Soft link-run : ./a.out t2.txt t2.txt ln

//note: no errors will be shown if code dosent work.