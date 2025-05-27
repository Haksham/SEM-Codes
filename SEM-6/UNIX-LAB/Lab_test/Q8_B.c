
// PARENT.C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t pid;
    int status;
    pid_t parent_pid = getpid();
    pid = fork();

    if (pid == 0) {
        pid_t child_pid = getpid(); 
        printf("Child process (PID: %d) executing...\n", child_pid);
        execl("./child", "child", "example.txt", (char *)NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } 
    else {
        printf("Parent process (PID: %d) executing...\n", parent_pid);
        waitpid(pid, &status, 0);
        printf("Parent process: Child process (PID: %d) has exited.\n", pid);
    }

    return 0;
}
//---------------------------------------------------------------------
// child.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    if (access(filename, F_OK) == 0) {
        printf("File '%s' exists and can be accessed.\n", filename);
    } else {
        printf("File '%s' does not exist or cannot be accessed.\n", filename);
    }

    return 0;
}

// gedit parent.c
// gedit child.c
// touch example.txt
// gcc -o child child.c
// gcc -o parent parent.c
// ./parent
// ./child example.txt