/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:49:06 by jbarredo          #+#    #+#             */
/*   Updated: 2022/03/09 20:01:21 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "Minitalk.h"

static void	check_signal(int sig)
{
	if (sig == SIGUSR2)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	send_signals(char c, int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (c & (128 >> j))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(2000);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
	{
		write(1, "Invalid arguments\n", 18);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1 || !pid || argv[2][0] == '\0')
		return (0);
	i = 0;
	while (argv[2][i])
	{
		signal(SIGUSR1, check_signal);
		signal(SIGUSR2, check_signal);
		send_signals(argv[2][i], pid);
		i++;
	}
	send_signals('\n', pid);
	return (0);
}
