#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_sys(const char *cm) {

    pid_t pid = fork();
    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cm, (char *)NULL);
        printf("execerror\n");
        exit(EXIT_FAILURE);
    }
    waitpid(pid, NULL, 0);
    return 0;
}

int main() {
    printf("executing ls-li\n");
    my_sys("ls -li");
    return 0;
}

// gcc p1.c
// ./a.out

// The output will show the execution of the command "ls -li" in the child process.