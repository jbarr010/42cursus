/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:55:25 by jbarredo          #+#    #+#             */
/*   Updated: 2021/09/01 20:14:39 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		s;
	int		m;
	long	sol;

	s = 0;
	m = 1;
	sol = 0;
	while (str[s] && (str[s] == '\t' || str[s] == '\r' || str[s] == ' '
			||str[s] == '\f' || str[s] == '\v' /*|| str[s] == '\n'*/))
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
