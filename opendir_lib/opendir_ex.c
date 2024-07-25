#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

//DIR *opendir(const char *name);
// This function helps to open a directory
// to read its contents.
// !NB - those functions serve perfectly for
// recreating ls command !

int main()
{
	DIR  * dir;
	struct dirent *entry;
	dir = opendir("opendir_aux_error");
	if (dir == 0)
		perror("ERROR! ");
	dir = opendir("opendir_aux_dir");
	
	while((entry = readdir(dir)) != NULL)
		printf("%s\n", entry->d_name);
	closedir(dir);
	
	return(0);
}