#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int s) {
    printf("\ncaught sigint %d\n", s);
    struct sigaction sa = {0};
    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);
    
    while (1){ 
    printf("\npress ctrl+c to continue...\n");
    pause();}
    return 0;
}

// gedit p1.c
// gcc p1.c
// ./a.out

// Press Ctrl+C to trigger the signal handler.