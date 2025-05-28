#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>
#include <fcntl.h>

void create_daemon() {
    if (fork() > 0) {
        exit(0); 
    }
    setsid();
    umask(0);
    chdir("/");
}

int main() {
    create_daemon();
    openlog("daemon_ex", LOG_PID, LOG_DAEMON);
    syslog(LOG_NOTICE, "Daemon is running...");

    return 0;
}

// gedit p1.c
// gcc p1.c
// ps aux (find id of ./a.out  with tty as "?") 
// tail -f /var/log/syslog (in new terminal to check if deamon is running)

// to stop deamon:
// sudo kill -9 <pid>      {use "ps aux" command and get pid of "./a.out" whose tty is "?"}