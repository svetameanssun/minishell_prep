#include <unistd.h>

//int isatty(int fd);
/*The isatty function in C is used to determine
if a file descriptor refers to a terminal (tty) device.
This can be useful when writing programs that need to
behave differently based on whether their input or output
is connected to a terminal (e.g., interactive vs. non-interactive behavior).*/

//isatty returns:
//1 (true) if the file descriptor refers to a terminal device.
//0 (false) if the file descriptor does not refer to a terminal device.
// use errno

int main()
{
	int fd_pipe[2];
	int pid = fork();
	pipe(fd_pipe);
	if (pid == 0)
	{
		
	}
	else
	{

	}
}