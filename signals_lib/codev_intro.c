
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <wait.h>

int main(int argc, char **argv)
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while(1)
		{
			printf("Some text\n");
			usleep(50000);
		}
	}
	else
	{
		sleep(10);
		kill(pid, SIGKILL);
		//wait(NULL);
	}
	pid = fork();
	if (pid ==0)
	{
		while(1)
		{
			printf("OTHER text\n");
			usleep(50000);
		}
	}
	else
	{
		sleep(50);
		kill(pid, SIGINT);
		//wait(NULL);
	}
	return(0);
}