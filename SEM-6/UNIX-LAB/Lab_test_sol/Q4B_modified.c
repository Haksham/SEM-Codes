#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int file = open("test.txt", O_RDWR);
    char buf[10];  
    read(file, buf, 5);  		
    buf[5] = '\0'; 
     		
    lseek(file, 0, SEEK_END); 
    dup2(file, STDOUT_FILENO);
    printf("%s", buf);
    return 0;
}

// run: gcc p1.c
// create a test.txt with "harsh codes"
// run: ./a.out