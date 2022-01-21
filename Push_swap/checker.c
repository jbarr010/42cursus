/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:41:49 by jbarredo          #+#    #+#             */
/*   Updated: 2022/01/12 17:07:51 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_char(int n, char **str)
{
	int	i;
	int	j;

	i = 1;
	while (i <= n)
	{
		j = 0;
		while(str[i][j])
		{
			if((str[i][j] >= 48 && str[i][j] <= 57) || str[i][j] == '-' || str[i][j] == ' ')
				j++;
			else
				return (0);
		}
		i++;
	}
	return(1);
}

int	check_rep(int n, int *stack)
{
	int	i;
	int	j;

	i = 0;
	while(i <= n)
	{
		j = i + 1;
		while(j <= n)
		{
			if(stack[i] == stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_limits(int n, int *stack)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		if ((stack[i] > 2147483647) || (stack[i] < -2147483648))
			return (0);
		i++;
	}
	return (1);
}
