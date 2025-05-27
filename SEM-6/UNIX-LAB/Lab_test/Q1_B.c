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

// gedit p1.c
// gedit src.txt ("helloworld")
// gcc p1.c
// ./a.out

// The output will show the parent and child processes reading the first 5 characters from "src.txt".
// The parent process will read "hello" and the child process will also read "hello".