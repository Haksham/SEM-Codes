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

// gedit p1.c
// gedit test.txt ("harsh codes")
// gcc p1.c
// ./a.out
// cat test.txt

// This program reads the first 5 characters from "test.txt" and appends them to the end of the file.
// The output will be "harsh" appended to the end of the file.