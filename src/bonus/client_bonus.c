#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int signum)
{
	if(signum == SIGUSR1)
		write(1, "Message received successfully\n",30);
}

void send_signal(pid_t pid, char *str, int size)
{
	char c;
	int i;
	int bits;
	int size_sent;

	i = 0;
	while (str[i])
	{
		size_sent = i * 4;
		printf("\rSending message: %i/%i bytes\n", size_sent, size);
		fflush(stdout);
		bits = 7;
		c = str[i];
		while (bits >= 0)
		{
			if (c >> bits & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
			bits--;
		}
		if (!str[i])
			break ;

	}
}

int main(int argc, char **argv)
{
	int index;
	int size;
	pid_t pid_server;

	signal(SIGUSR1, &handler);
	if (argc != 3)
	{
		write(1, "Error: ./client <PID> <MESSAGE>\n", 34);
		return (1);
	}
	pid_server = atoi(argv[1]);
	size = strlen(argv[2]) * 4;
	send_signal(pid_server, argv[2], size);
	while(1)
		pause();
	return (0);
}
