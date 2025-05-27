#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
int main(){
	
	int src=open("src.txt",O_RDONLY);
	int dest=open("dest.txt",O_WRONLY);
	char buf[10];
	int pos=lseek(src,0,SEEK_END);
	
	while(--pos>=0){
		lseek(src,pos,SEEK_SET);
		read(src,buf,1);
		write(dest,buf,1);
	}
	return 0;
}

// gedit p1.c
// gedit src.txt ("harsh codes")
// touch dest.txt (empty file)
// gcc p1.c
// ./a.out
// cat dest.txt

// This program reads the contents of "src.txt" in reverse order and writes them to "dest.txt".
// The output will be "sedoc hsrah" in "dest.txt".