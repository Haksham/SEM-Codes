#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int src = open(argv[1], O_RDONLY);
    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf;
    off_t i = lseek(src, 0, SEEK_END);

    while (--i >= 0) {
        lseek(src, i, SEEK_SET);
        read(src, &buf, 1);
        write(dest, &buf, 1);
    }

    write(1, "DONE\n", 5);
    return 0;
}

// make src.txt with some text and dest.txt as empty
// run: gcc p1.c
// ./a.out src.txt dest.txt

// Do on your own risk
// This code will not show you errors if they occur.
// Then you have to debug yourself.