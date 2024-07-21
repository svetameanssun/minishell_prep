#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>
// It does the same what the sigaction does,
// !BUT! in the manual it says that it is 
// better to use sigaction.
//

void handle_sigtstp(int sig)
{
	printf("Stop not allowed!\n");
}


int main(int argc, char **argv)
{

	signal(SIGTSTP, &handle_sigtstp);
	int x;
	printf("Input number: \n");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return(0);
}