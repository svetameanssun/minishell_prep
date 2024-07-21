#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>

// I will create a program that asks the user a simple question.
// It the user takes longer than 5 sec to answer, 
// they will receive a hint.
// We will do that using 2 processes


void handle_sigusr1(int sig)
{
	printf(" (HINT) Remember that multiplication is repetitive addition\n");
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
		//child proces
		// we want to wait for 5 min,
		// and then send signal to the arent proc,
		// for it to give a hint.
		sleep(5);
		kill(getppid(), SIGUSR1);
		// if we leave the line above without handler,
		// it will terminate the parent process.
		// We have to add the handler in the parent process.

	}
	else
	{
		//parent process
		struct sigaction act = { 0 };
		// to make sure everything in the struct is set to zero
		act.sa_flags = SA_RESTART;
		act.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &act, NULL);

		int x;
		// if we use a local variable, the hint will show up
		// even if the user answers correctly.
		// If the answer is incorrect, the program will terminate
		//after giving a hint.
		// TO PREVENT IT, I WILL USE THE GLOBAL VARIABLE Y
		// INSTEAD OF X.
		printf("What is the result of 3 x 5: ");
		scanf("%d", &x);
		if (x == 15)
			printf("CORRECT!\n");
		else
			printf("WRONG\n");
		wait(NULL);
	}

	return 0;
}