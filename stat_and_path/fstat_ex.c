#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

// int fstat(int fd, struct stat *statbuf);
int main()
{
	int fd = open("fstat_aux.txt", O_RDONLY);
	struct stat buf;
	
	fstat(fd,&buf);
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