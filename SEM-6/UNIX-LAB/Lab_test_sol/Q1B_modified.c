#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    int file = open("src.txt", O_RDONLY);
    char buf[20];

    if (fork() == 0) 
   {    read(file, buf, 5); 
        buf[5] = '\0';
        printf("Child read: %s\n", buf);
    } 
     else 
   {    read(file, buf, 5);                    			
        buf[5] = '\0';
        printf("Parent read: %s\n", buf);
    }

    return 0;
}

// create a test.txt with "helloworld"
// run: gcc p1.c
// run: ./a.out

// Do on your own risk
// This code will not show you errors if they occur.
// Then you have to debug yourself.