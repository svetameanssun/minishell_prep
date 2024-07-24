#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>


//   int unlink(const char *path);

/*The unlink function in C is used to delete a file.
It's a part of the POSIX standard and is defined in the <unistd.h> header.
When you call unlink on a file, it removes the link (or directory entry)
for the file specified by its pathname. If this was the last link to the file
and no process has the file open, the file is deleted and the disk space
it occupied is freed.*/
int main()
{
	char buf[10000];
	size_t size = 10000;
	int pid = fork();
	if (pid == 0)
	{
		open("unlink_aux.txt", O_RDONLY, O_CREAT, 0644);
		while(1)
		{
			sleep(5);
			printf("Running...");
		}
	}
	else{
		char *path = "unlink_aux.txt";
		int i = unlink(path);
		printf(" %d\n", i);
	}
	return(0);
}