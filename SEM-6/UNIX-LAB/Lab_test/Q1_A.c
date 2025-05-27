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

// make src.txt with some text and dest.txt as empty
// run: gcc p1.c
// ./a.out src.txt dest.txt

// Do on your own risk
// This code will not show you errors if they occur.
// Then you have to debug yourself.