
// PARENT.C
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("Child process (PID: %d) executing...\n", getpid());
        execl("./child", "child", "example.txt", (char *)NULL);
    } else {
        printf("Parent process (PID: %d) executing...\n", getpid());
        waitpid(pid, NULL, 0);
        printf("Parent process: Child process (PID: %d) has exited.\n", pid);
    }
    return 0;
}
//---------------------------------------------------------------------
// child.c

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (access(argv[1], F_OK) == 0)
        printf("File '%s' exists and can be accessed.\n", argv[1]);
    else
        printf("File '%s' does not exist or cannot be accessed.\n", argv[1]);
    return 0;
}

// gedit parent.c
// gedit child.c
// touch example.txt
// gcc -o child child.c
// gcc -o parent parent.c
// ./parent
// ./child example.txt