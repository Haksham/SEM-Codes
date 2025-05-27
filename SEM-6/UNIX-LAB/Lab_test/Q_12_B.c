// p1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void err_sys(const char *message) {
    perror(message);
    exit(1);
}

int main(void) {
    pid_t pid;
    char *env_init[] = {"USER=unknown", "PATH=/tmp",NULL};
    if (pid == 0) {execle("/home/cselab3/test/echoall", "echoall", "myarg1", "MY ARG2", (char *)0, env_init);}
    waitpid(pid, NULL, 0);
    execlp("/home/cselab3/test/echoall", "echoall", "only 1 arg", (char *)0);
    return 0;
}
//-------------------------------------------------------------
// echoall.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    char **ptr;
    extern char **environ;
    for (i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    for (ptr = environ; *ptr != 0; ptr++) {
        printf("%s\n", *ptr);
    }
    return 0;
}


// gedit p1.c
// pwd (copy pass and paste in p1.c + /echoall)
// gedit echoall.c
// gcc -o echoall echoall.c
// gcc p1.c
// ./a.out