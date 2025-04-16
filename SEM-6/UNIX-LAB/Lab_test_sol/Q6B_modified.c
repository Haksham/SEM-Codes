#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>

int main(){
	
    int file=open("rex.txt",O_RDONLY);
    char buf[20];
    struct stat st;
	
    read(file, buf, 20); 
    buf[20] = '\0';
    printf("First 20 chars     : %s\n", buf);

    lseek(file, 10, SEEK_SET);     
    read(file, buf, 20);
    buf[20] = '\0';
    printf("From 10th byte     : %s\n", buf);

    lseek(file, 10, SEEK_CUR);     
    read(file, buf, 20);
    buf[20] = '\0';
    printf("10 bytes ahead     : %s\n", buf);
	
    stat(file,&st);
    printf("\n%ld",st.st_size);
}

// run: gcc p1.c
// create test.txt with 100 char text.
// run: ./a.out