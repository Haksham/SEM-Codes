#include <dirent.h>
#include<time.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	struct dirent *dir;
	struct stat mystat;
	DIR *dp=opendir(".");
	while(dir = readdir(dp))
	{
		printf("\n%ld %o %d %d %s %s\n",
            mystat.st_ino,mystat.st_mode,mystat.st_uid,mystat.st_gid,ctime(&mystat.st_atime),dir->d_name);
	}
}

// run: gcc p1.c
// run: ./a.out