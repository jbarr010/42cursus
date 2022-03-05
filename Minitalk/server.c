/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:56:32 by jbarredo          #+#    #+#             */
/*   Updated: 2022/03/05 20:19:56 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "Minitalk.h"

void	handle_sig(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;

	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(c, 1);
		bits = 0;
		c = 0xFF;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
		write (1, "Invalid number of arguments\n", 28);
	else
	{
		pid = getpid();
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
		signal(SIGUSR1, handle_sig);
		signal(SIGUSR2, handle_sig);
		while (1)
			pause();
	}
}
