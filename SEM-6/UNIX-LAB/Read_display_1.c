// Q.1 c program to read from keyboard and display.

#include "apue.h"
#define BufferSize 4096
int main(void){
  int n;
  char buff[BufferSize];
  while((n=read(STDIN_FILENO,buff,BufferSize))>0){
    if(write(STDOUT_FILENO,buff,n)!=n) { perrer("write error"); }
  }
  if(n<0) { perror("read error"); }
  exit(0);
}

// To Compile: cc file.c -> ./a.out