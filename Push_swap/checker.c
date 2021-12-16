/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:41:49 by jbarredo          #+#    #+#             */
/*   Updated: 2021/12/16 20:30:55 by jbarredo         ###   ########.fr       */
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
			if(str[i][j] < 48 || str[i][j] > 57)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return(1);
}
