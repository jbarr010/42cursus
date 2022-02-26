/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:02:49 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/26 19:46:07 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int		s;
	int		m;
	long	sol;

	s = 0;
	m = 1;
	sol = 0;
	while (str[s] && (str[s] == '\t' || str[s] == '\r' || str[s] == ' '
			||str[s] == '\f' || str[s] == '\v' || str[s] == '\n'))
		s++;
	if (str[s] == '+' || str[s] == '-')
	{
		if (str[s] == '-')
			m *= -1;
		s++;
	}
	while (str[s] >= '0' && str[s] <= '9')
	{
		sol = (str[s] - '0') + (sol * 10);
		if ((sol * m < -2147483648) || (sol * m > 2147483648))
			return ((sol * m < -2147483648) - 1);
		s++;
	}
	return (sol * m);
}

int	ft_atoi_error(char *str)
{
	int		s;
	int		m;
	long	sol;

	s = 0;
	m = 1;
	sol = 0;
	while (str[s] && (str[s] == '\t' || str[s] == '\r' || str[s] == ' '
			||str[s] == '\f' || str[s] == '\v' || str[s] == '\n'))
		s++;
	if (str[s] == '+' || str[s] == '-')
	{
		if (str[s] == '-')
			m *= -1;
		s++;
	}
	while (str[s] >= '0' && str[s] <= '9')
	{
		sol = (str[s] - '0') + (sol * 10);
		if ((sol * m < -2147483648) || (sol * m > 2147483647))
			return (0);
		s++;
	}
	return (1);
}

int	*fill_stack(int n, char **parm)
{
	int	*stack;
	int	i;

	stack = malloc(sizeof(int) * n);
	i = n - 1;
	while (i >= 0)
	{
		if (ft_atoi_error(parm[i + 1]))
		{
			stack[i] = ft_atoi(parm[i + 1]);
			i--;
		}
		else
		{
			write (1, "Error\n", 6);
			exit(0);
		}
	}
	return (stack);
}

int	*fill_parm(int i, char **str)
{
	int	*stack;
	int	n;

	stack = malloc(sizeof(int) * i);
	n = i - 1;
	while (n >= 0)
	{
		if (ft_atoi_error(str[n]))
		{
			stack[n] = ft_atoi(str[n]);
			n--;
		}
		else
		{
			write (1, "Error\n", 6);
			exit (0);
		}
	}
	return (stack);
}
