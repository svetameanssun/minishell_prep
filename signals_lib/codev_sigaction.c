#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>
// How to manage signals and how to prevent
// the process to be sent to the background?
// How to ignore |ctrl + z| command sent from the terminal
// or make my process to do another thing intead of stopping?
// I Want to handle this signal differently. How to do it? 

/*void handle_sigtstp(int sig)
{
	printf("Stop not allowed!\n");
}*/


int main(int argc, char **argv)
{

	//struct sigaction sa;
	//sa.sa_handler = &handle_sigtstp;
	//sa.sa_flags = SA_RESTART; // we need this because we use the combination of
							  // SIGTSTP and scanf, it doesn't work well
							  // if we do not provide this flag
	
	//sigaction(SIGTSTP, &sa, NULL);
	int x;
	printf("Input number: \n");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return(0);
}