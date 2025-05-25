#include <stdio.h>
#include <utime.h>
#include <sys/stat.h>

int main() {
    struct stat st;
    struct utimbuf tt;

    stat("src.txt", &st);

    tt.actime = st.st_atime; 
    tt.modtime = st.st_mtime;

    utime("dest.txt", &tt);
    
    return 0;
}

// run: gcc p1.c
// create 2 files t1.txt , t2.txt
// run: ./a.out t1.txt t2.txt

// note: errors will not be displayed if code doesnt work.