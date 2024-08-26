/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:21:09 by grial             #+#    #+#             */
/*   Updated: 2024/07/18 17:59:01 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minitalk.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "Message received successfully\n", 30);
		exit (0);
	}
}

void	send_signal(pid_t pid, char c)
{
	int		i;
	int		bits;

	i = 0;
	bits = 7;
	while (bits >= 0)
	{
		if (c >> bits & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(400);
		bits--;
	}
	i++;
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	int		i;

	i = 0;
	signal(SIGUSR1, &handler);
	if (argc != 3)
	{
		write(1, "Error: ./client <PID> <MESSAGE>\n", 34);
		return (1);
	}
	pid_server = atoi(argv[1]);
	while (argv[2])
	{
		send_signal(pid_server, argv[2][i]);
		i++;
	}
	send_signal(pid_server, '\0');
	while (1)
		pause();
	return (0);
}
