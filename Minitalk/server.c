#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handle_sig1(int signum)
{
   printf("signal %d received.\n", signum);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	signal(SIGUSR1, handle_sig1);
	while (1)
		pause();
}
