#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char buff[10];
    int src = open(argv[1], O_RDONLY);
    int dest = open(argv[2], O_WRONLY);
   
    read(src, buff, 10);
    write(dest, buff, 10);
    return 0;
}

// gedit p1.c
// gedit src.txt (some text > 10 char)
// gedit dest.txt (empty)
// gcc p1.c
// ./a.out src.txt dest.txt
// cat dest.txt