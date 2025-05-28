// parent.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (fork() == 0) { 
        execl("./child", "child", argv[1], argv[2], (char *)NULL);
    }
    else { 
        wait(NULL);
        printf("Child exited.....\n");
    }
    return 0;
}

// ---------------------------------------------------------
// child.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Sum: %d\n", atoi(argv[1]) + atoi(argv[2]));
    return 0;
}

// gedit parent.c
// gedit child.c
// gcc -o parent parent.c
// gcc -o child child.c
// ./parent 5 6