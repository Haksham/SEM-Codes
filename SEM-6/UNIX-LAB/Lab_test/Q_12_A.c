#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        printf("Child (PID: %d) exiting...\n", getpid());
    } else {
        printf("Parent (PID: %d) sleeping. Check 'ps' for zombie.\n", getpid());
        sleep(10); // Observe zombie with 'ps'
        wait(NULL); // Solution: reaps the zombie
        printf("Parent removed the child. No zombie now.\n");
    }
    return 0;
}

// gedit p1.c
// gcc p1.c
// ./a.out

// use on new terminal to check <defunct> process which is zombie : ps -ef | grep defunct
// after 10 seconds, run the command again to see that the zombie process is gone.