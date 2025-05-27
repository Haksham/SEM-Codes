//inter.c
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {  
        execl("textinterpreter", "test", "myarg1", "myarg2", "myarg4", (char *)0);
    } 
    else {waitpid(pid, NULL, 0);}
    return 0;
}

// echoall.c 
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
int i;
for(i=0;i<argc;i++){
printf("argv[%d]= %s\n",i,argv[i]);
}
return 0;
}


// textintepreter (command: pwd , use that path in this file)
#! /home/cselab3/test/p3/echoall my2
[Ex. #! /home/cselab3/test/p3/echoall my2]

// gedit inter.c
// gedit echoall.c
pwd (copy path)
// gedit textinterpreter (paste path + /echoall)
// gcc -o inter inter.c
// gcc -o echoall echoall.c
// ./inter