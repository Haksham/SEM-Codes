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

// gedit p1.c
// touch src.txt
// touch dest.txt (create dest file 1 min after creating src file)
// la -l (check the access and modification times of src.txt and dest.txt)
// gcc p1.c
// ./a.out
// ls -l src.txt dest.txt (recheck the access and modification times which should now match)
