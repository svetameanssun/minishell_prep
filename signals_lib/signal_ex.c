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
	while(1)
	{
		printf("Running...\n");
		sleep(1);
	}
	return(0);
}