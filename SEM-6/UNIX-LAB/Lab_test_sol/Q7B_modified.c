#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 == 0){ 
        pid2 = fork();
        if (pid2 == 0) {
            sleep(5);
            printf("Child pid is: %d\n", getpid());
            printf("Second child, parent pid = %ld\n", (long)getppid());
            exit(0);
        } else {
            printf("Child pid: %d\n", getpid());
            exit(0);
        }
    }

    pid3 = waitpid(pid1, NULL, 0);

    printf("Terminated child's pid: %d\n", pid3);

    exit(0);
}
// run: gcc p1.c
// run: ./a.out

// not much changes *.*