#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
// It shows the error message that the system would give

int main()
{
	DIR *dir;

	int i = 0;
	while(i <= 133)
	{
		printf("%d - %s\n", i, strerror(i));
		i++;
	}
	opendir("asasasasa");
	printf("%d - %s\n", errno, strerror(errno));
	return(0);
}
