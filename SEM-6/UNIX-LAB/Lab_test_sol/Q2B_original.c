#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        printf("Hard linking %s and %s\n", argv[1], argv[2]);
        if (link(argv[1], argv[2]) == 0)
            printf("Hard link created successfully.\n");
        else
            perror("Error creating hard link");
    }
    else if (argc == 4)
    {
        printf("Soft linking %s and %s\n", argv[1], argv[2]);
        if (symlink(argv[1], argv[2]) == 0)
            printf("Soft link created successfully.\n");
        else
            perror("Error creating soft link");
    }
    return 0;
}

// run: gcc p1.c

// create t1.txt with some text
// Hard link-run : ./a.out t1.txt t2.txt

// remove t2.txt ,run: rm t2.txt
// Soft link-run : ./a.out t2.txt t2.txt ln