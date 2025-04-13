// not given in previous ques

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        return 1;
    }

    printf("File Name       : %s\n", argv[1]);
    printf("Hard Links      : %ld\n", fileStat.st_nlink);
    printf("Last Access Time: %s", ctime(&fileStat.st_atime));
    printf("Inode Number    : %ld\n", fileStat.st_ino);
    printf("User ID (UID)   : %d\n", fileStat.st_uid);
    printf("Group ID (GID)  : %d\n", fileStat.st_gid);

    return 0;
}