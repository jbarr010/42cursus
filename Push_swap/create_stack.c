/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:02:49 by jbarredo          #+#    #+#             */
/*   Updated: 2021/12/16 20:31:11 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
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

int	*fill_stack(int n, char **parm)
{
	int	*stack;
	int	i;

	stack = malloc(sizeof(int) * n);
	i = n;
	while(i > 0)
	{
		stack[i] = ft_atoi(parm[i]);
		i--;
	}
	return (stack);
}

void	print_stack(int *stack, int n)
{
	int	i;
	int	*A;

	A = stack;
	i = n;
	while (i > 0)
	{
		printf("%d\n", A[i]);
		i--;
	}
}
