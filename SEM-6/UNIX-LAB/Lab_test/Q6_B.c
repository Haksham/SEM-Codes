#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define REGION_SIZE 100
#define READ_SIZE 50

int main(int argc, char *argv[]) {

    int fd = open(argv[1], O_RDWR);

    struct stat st;
    fstat(fd, &st);
    off_t filesize = st.st_size;
    off_t region_start = filesize - REGION_SIZE;

    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = region_start;
    fl.l_len = REGION_SIZE;
    fl.l_pid = 0;

    fcntl(fd, F_GETLK, &fl);
    if (fl.l_type != F_UNLCK) {
        printf("Region is locked by process with PID: %d\n", fl.l_pid);
        close(fd);
        return 0;
    }

    fl.l_type = F_WRLCK;
    fcntl(fd, F_SETLK, &fl);

    off_t read_start = filesize - READ_SIZE;
    if (lseek(fd, read_start, SEEK_SET) == -1) {
        fl.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &fl);
        close(fd);
        return 1;
    }

    char buffer[READ_SIZE + 1];
    int bytes_read = read(fd, buffer, READ_SIZE);

    buffer[bytes_read] = '\0';
    printf("Last 50 bytes:\n%s\n", buffer);
    

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    return 0;
}