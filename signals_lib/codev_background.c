#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>
// Bringing a process to the background means stopping the process.
// To stop the process from the terminal where you execute the program - |ctrl + z|.
// To resume the process from the terminal where you execute the program - |fg <id>|
// !NB - the terminal sends the signal SIGTSTP with ctrl + z command
//		and SIGCONT with fg command.
int main(int argc, char **argv)
{
	int x;
	int pid = getpid();
	printf("Process id: %d\n", pid);
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
}