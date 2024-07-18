#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int sig, siginfo_t *info, void *context)
{
	static  char	c;
	static  int	bit_index = 7;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << bit_index);
	bit_index--;
	if(bit_index < 0)
	{
		if(c == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		bit_index = 7;
		c = 0;
	}
}

int main(void)
{
    pid_t pid;
    struct sigaction sa;

    pid = getpid();
    if (pid == -1)
    {
        return 0;
    }
    printf("PROCESS ID: %i\n", pid);

    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();

    return 0;
}
