#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char buf[1000];
	size_t size = 1000;
	char *res = malloc(sizeof(char) * 1000);
	res = getcwd(buf, size);
	printf("%s", res);
	printf("\n-----\n");
	///home/stitovsk/Desktop/minishell_prep/various_functs
	
	char *new_path = "/home/stitovsk/Desktop/minishell_prep";
	chdir(new_path);
	res = getcwd(buf, size);
	printf("%s", res);
	printf("\n-----\n");
	return(0);
}