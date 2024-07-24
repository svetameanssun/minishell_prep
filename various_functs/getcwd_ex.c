#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char buf[10000];
	size_t size = 10000;
	printf("%s", getcwd(buf, size));
	return(0);
}
