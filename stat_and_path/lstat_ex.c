#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// int lstat(const char *pathname, struct stat *statbuf);
// difference with stat:
// execute (search) permission is required on all of the directories
// in pathname that lead to the file

int main()
{
	char buffer[1000];
	size_t size = 1000;
	char *path = getcwd(buffer, size);
	struct stat buf;
	lstat(path, &buf);
	printf("Number of hard links to the file: %ld\n", buf.st_nlink);
	printf("The user ID of the owner of the file: %d\n", buf.st_uid);
	printf("The ID of the group owner of the file: %d\n", buf.st_gid);
	printf("Size of the file(if it is a regular file of a symbolic link): %ld\n",buf.st_size);
	
	printf("Gives the 'preferred' block size for efficient filesystem I/O: %ld\n", buf.st_blksize);
	printf("Indicates the number of blocks allocated to the file, in 512-byte units: %ld\n", buf.st_blocks);
	printf("Time of the last access of the file data: %ld \n", buf.st_atime);
	printf("Time of the last modification of the file data: %ld \n", buf.st_mtime);
	printf("The file's last status change timestamp (last change to the inode): %ld\n", buf.st_ctime);

}