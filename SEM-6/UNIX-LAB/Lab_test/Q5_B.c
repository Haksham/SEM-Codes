#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void s_h(int sn) {
    printf("\ncaught sigint %d\n", sn);

    struct sigaction sa;
    sa.sa_handler = SIG_DFL; 
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = s_h; 
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        printf("press ctrl+c to trigger\n");
        pause();
    }
    return 0;
}

// gedit p1.c
// gcc p1.c
// ./a.out

// Press Ctrl+C to trigger the signal handler.