// parent.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid == 0) { 
        execl("./child", "child", argv[1], argv[2], (char *)NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    }
    else { 
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally\n");
        }
    }
    return 0;
}

// ---------------------------------------------------------
// child.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1 = atoi(argv[1]); 
    int num2 = atoi(argv[2]); 
    int sum = num1 + num2;
    printf("Sum: %d\n", sum);
    return 0;
}

// gedit parent.c
// gedit child.c
// gcc -o parent parent.c
// gcc -o child child.c
// ./parent 5 6