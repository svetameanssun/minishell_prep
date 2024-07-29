#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

//The ttyname function in C is used to obtain the name of the terminal (TTY) device
//associated with a given file descriptor. This function is useful
//when you need to identify the specific terminal or console
//being used by a program or process.

//char *ttyname(int fd);
// use errno

int main()
{
	int fd = open("ttynam_aux.txt", O_RDONLY | O_CREAT, 0644);
	dup2(STDOUT_FILENO, fd);
	printf("%s\n", ttyname(fd));
}