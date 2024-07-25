#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

// The  perror()  function  produces a message on standard error
// describing the last error encountered during
// a call to a system or library function.

int main()
{
	DIR  * dir;
	dir = opendir("opendir_aux_error");
	if (dir == 0)
	{
		perror("");
	}
}