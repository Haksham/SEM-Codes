#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main() 
{
    int fd = open("test.txt", O_RDWR);
    pid_t pid = fork();
    
    if (pid == 0) 
    {
        char buffer[10];
        read(fd, buffer, 5);
        buffer[5] = '\0';
        printf("Child read: %s\n", buffer);
    } 
    else 
    {
        wait(NULL);
        char buffer[10];
        read(fd, buffer, 5);
        buffer[5] = '\0';
        printf("Parent read: %s\n", buffer);
    }
    return 0;
}

// create a test.txt with "helloworld"
// run: gcc p1.c
// run: ./a.out

// Do on your own risk
// This code will not show you errors if they occur.
// Then you have to debug yourself.