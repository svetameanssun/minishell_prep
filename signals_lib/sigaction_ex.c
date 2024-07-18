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
	sigfillset(&set);
}