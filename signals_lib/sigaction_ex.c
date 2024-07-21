#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler_sig(int sig)
{
	printf("SING: %d\n", sig);
}

int main(void)
{
	sigset_t set;
	sigemptyset(&set);
	struct sigaction act;
	struct sigaction oldact;
	act.sa_handler = &handler_sig;
	sigaction(SIGINT, &act, &oldact);
	while(1)
	{
		printf("Running...\n");
		sleep(50);
	}

}
