/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:56:18 by jbarredo          #+#    #+#             */
/*   Updated: 2022/03/05 20:16:13 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "Minitalk.h"

void	send_signals(char c, int pid)
{
	int	j;

	j = 0;
	while(j < 8)
	{
		if (c & (128 >> j))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
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
	i = 0;
	while (argv[2][i])
	{
		send_signals(argv[2][i], pid);
		i++;
	}
	send_signals('\n', pid);
}
