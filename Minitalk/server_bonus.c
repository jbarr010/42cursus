/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:48:45 by jbarredo          #+#    #+#             */
/*   Updated: 2022/03/09 15:21:03 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "Minitalk.h"

static void	handle_sig(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
	{
		kill(info->si_pid, SIGUSR2);
		c ^= 0x80 >> bits;
	}
	else if (signum == SIGUSR2)
	{
		kill(info->si_pid, SIGUSR2);
		c |= 0x80 >> bits;
	}
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
	int					pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
		write (1, "Invalid number of arguments\n", 28);
	else
	{
		pid = getpid();
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
		act.sa_sigaction = handle_sig;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		while (1)
		{
			sigaction(SIGUSR1, &act, NULL);
			sigaction(SIGUSR2, &act, NULL);
			pause();
		}
	}
}
