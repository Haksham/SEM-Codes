#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid, pid1, pid2, pid3;

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) { // first child
        if ((pid3 = fork()) < 0) {
            printf("fork error\n");
        } else if (pid3 == 0) {
            sleep(5);
            printf("Child pid is: %d\n", getpid());
            printf("Second child, parent pid = %ld\n", (long)getppid());
            exit(0);
        } else {
            printf("Child pid: %d\n", getpid());
            exit(0);
        }
    }

    if ((pid2 = waitpid(pid, NULL, 0)) != pid) {
        printf("waitpid error\n");
    }

    printf("Terminated child's pid: %d\n", pid2);

    exit(0);
}
// run: gcc p1.c
// run: ./a.out