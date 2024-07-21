#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>

// I will create a program that asks the user a simple question.
// It the user takes longer than 5 sec to answer, 
// they will receive a hint.
// We will do that using 2 processes

int main(int argc, char **argv)
{
	int pid = fork();
	if (pid == -1)
	{
		return(1);
	}

	if (pid == 0)
	{
		//child proces
		// we want to wait for 5 min,
		// and then send signal to the arent proc,
		// for it to give a hint.
		sleep(5);
		kill(getppid(), SIGUSR1);

	}
	else
	{
		//parent process
		int x;
		printf("What is the result of 3 x 5: ");
		scanf("%d", &x);
		if (x == 15)
			printf("CORRECT!\n");
		else
			printf("WRONG\n")
	}

	return 0;
}