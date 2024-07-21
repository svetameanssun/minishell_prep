#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler_sig(int sig)
{
	printf("SIG: %d\n", sig);
}

int main()
{	
	signal(SIGINT, handler_sig);
	signal(SIGKILL, SIG_IGN);
	while(1)
	{
		printf("Running...\n");
		sleep(1);
	}

	return(0);
}

// SIGINT, handler_sig
// SIGKILL, SIG_IGN