/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:09:00 by grial             #+#    #+#             */
/*   Updated: 2024/07/18 17:10:08 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
		exit(0);
}

void	send_signal(pid_t pid, char *str)
{
	char	c;
	int		i;
	int		bits;

	i = 0;
	while (1)
	{
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
		if (c == '\0')
			break ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;

	signal(SIGUSR1, &handler);
	if (argc != 3)
	{
		write(1, "Error: ./client <PID> <MESSAGE>\n", 34);
		return (1);
	}
	pid_server = atoi(argv[1]);
	send_signal(pid_server, argv[2]);
	while (1)
		pause();
	return (0);
}
