#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>
// When talking about handling, some signals can be handled
// like SIGTSTP; others are handled like SIGCONT.
// And a few signals are imposible to handle (it is not allowed by the system).

void handle_sigtstp(int sig)
{
	printf("%d is not allowed!", sig);
	fflush(stdout); 
	//if we change the handler of SIGTSTP,
	//the signal is not executed,
	// the process does the action above insted;
}


void handle_sigcont(int sig)
{
	printf("Introduce a number: \n");
	// When we try to handle SIGCONT,
	// the line "Introduce a number: \n" is printed, 
	// but it doesn't substitute the signal!
	// SIGCONT is different!
	
}

int main(int argc, char ** argv)
{
	struct sigaction act;
	act.sa_handler = &handle_sigcont;
	act.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &act, NULL);
	
	int x;
	printf("Introduce a number: \n");
	
	scanf("%d", &x);
	printf("%d * 5 = %d\n", x, x * 5);
}