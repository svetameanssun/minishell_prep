#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
/*The ttyslot function in C is used to find the index
of the current terminal session in the system's terminal
line database. This database, typically found at /var/run/utmp
or /var/adm/utmp, records information about all active terminal
sessions on a Unix-like system. */

int main()
{
	int res = ttyslot();
	printf("Current terminal session: %d\n", res);
	printf("%s", strerror(errno));
}