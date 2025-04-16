// not given in previous ques
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

int main() {
    struct stat st;

    open("src.txt",O_RDONLY);
    
    printf("Hard Links      : %ld\n", st.st_nlink);
    printf("Mode            : %o\n", st.st_mode);
    printf("Inode Number    : %ld\n", st.st_ino);
    printf("User ID (UID)   : %d\n", st.st_uid);
    printf("Group ID (GID)  : %d\n", st.st_gid);

    return 0;
}


// run: gcc p1.c
// run: ./a.out

// note: 
// Do on your own risk
// This code will not show you errors if they occur.
// Then you have to debug yourself.