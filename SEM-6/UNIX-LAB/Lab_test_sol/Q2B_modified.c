#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        printf("Hard linking %s and %s\n", argv[1], argv[2]);
        link(argv[1], argv[2]);
        printf("Hard link created successfully.\n");
    }
    else if (argc == 4)
    {
        printf("Soft linking %s and %s\n", argv[1], argv[2]);
        symlink(argv[1], argv[2]);
        printf("Soft link created successfully.\n");
    }
    return 0;
}

// run: gcc p1.c

// create t1.txt with some text
// Hard link-run : ./a.out t1.txt t2.txt

// remove t2.txt ,run: rm t2.txt
// Soft link-run : ./a.out t2.txt t2.txt ln

//note: no errors will be shown if code dosent work.