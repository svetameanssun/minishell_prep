#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>

// Program that asks the user a simple question.
// It the user takes longer than 5 sec to answer, they will receive a hint.
// IMPROVED by using global var

int y = 0;

void handle_sigusr1(int sig)
{
	if (y == 0) // we added this condition along woth the global variable 
	{
		printf("\n(HINT) Remember that multiplication is repetitive addition\n");
	}
}

int main(int argc, char **argv)
{
	int pid = fork();
	if (pid == -1)
	{
		return(1);
	}

	if (pid == 0)
	{
		sleep(5);
		kill(getppid(), SIGUSR1);

	}
	else
	{
		//parent process
		struct sigaction act = { 0 };
		act.sa_flags = SA_RESTART;
		act.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &act, NULL);

		printf("What is the result of 3 x 5: ");
		scanf("%d", &y);
		if (y == 15)
			printf("CORRECT!\n");
		else
			printf("WRONG\n");
		wait(NULL);
	}

	return 0;
}