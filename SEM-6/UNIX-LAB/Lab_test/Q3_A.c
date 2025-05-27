#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    struct dirent *dir;
    DIR *dp=opendir(".");
		while ((dir = readdir(dp)) != NULL)
		{
				int fd = open(dir->d_name, O_RDWR);
				int n = lseek(fd, 0, SEEK_END);
				if (!n)
				{unlink(dir->d_name);}
		}
    return 0;
}

// create an empty file (ex:empty.txt)
// run: ls
// run: gcc p1.c
// run: ./a.out
// run: ls

// The program will delete all empty files in the current directory.