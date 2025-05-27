//inter.c
#include <stdio.h>
#include <unistd.h>
int main() {
    execl("textinterpreter", "test", "myarg1", "myarg2", "myarg3", (char *)0);
    return 0;
}

// echoall.c 
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    int i;
    for(i=0; i<argc; i++){
        printf("argv[%d]= %s\n",i,argv[i]);
    }
    return 0;
}


// textintepreter (command: pwd , use that path in this file)
#! /home/cselab3/test/p3/echoall

// gedit inter.c
// gedit echoall.c
// pwd (run on new terminal of same folder)(copy path)
// gedit textinterpreter (paste path + /echoall)
// chmod 777 textinterpreter
// gcc -o inter inter.c
// gcc -o echoall echoall.c
// ./inter