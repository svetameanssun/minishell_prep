#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>

// I want to control whether the child executes or not
// from the parent process using signals

int main(int argc, char **argv)
{
	int pid = fork();
	if (pid == -1)
		return(1);

	if (pid == 0)
	{
		while(1)
		{
			printf("Some output\n");
			usleep(50000);// suspends execution of the calling thread
			//for (at least) usec miscoseconds. 1000000 mcrsec = 1 sec
		}
	}
	else
	{
		kill(pid, SIGSTOP);//I stop the child process;
		sleep(1);//sleep causes the calling thread to sleep untill the number of real-time secs
				//specified have elapsed or until a signal arrives which is not ignored.
		kill(pid, SIGCONT); // I resume the child process
		sleep(1);
		kill(pid, SIGKILL);// I kill the child process
		wait(NULL);
	}
}