#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>
#include <fcntl.h>

void create_daemon() {
    pid_t pid = fork();
    if (pid > 0) {
        exit(EXIT_SUCCESS); 
    }
    setsid();
    umask(0);
    chdir("/");
    open("/dev/null", O_RDWR);
}

int main() {
    create_daemon();
    openlog("daemon_ex", LOG_PID, LOG_DAEMON);
    while (1) {
        syslog(LOG_NOTICE, "Daemon is running...");
        sleep(30);
    }
    closelog();
    return EXIT_SUCCESS;
}

// gedit p1.c
// gcc p1.c
// ps aux (find id of ./a.out  with tty as "?") 
// tail -f /var/log/syslog (in new terminal to check if deamon is running)

// to stop deamon:
// sudo kill -9 <pid>      {use "ps aux" command and get pid of "./a.out" whose tty is "?"}