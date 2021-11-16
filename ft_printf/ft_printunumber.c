/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunumber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:13:58 by jbarredo          #+#    #+#             */
/*   Updated: 2021/11/15 20:03:58 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printunumber(unsigned int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count = ft_printchar('-');
		num = -num;
	}
	else if (num < 10)
	{
		count = ft_printchar(num + 48);
	}
	else
	{
		count = ft_printunumber(num / 10);
		count += ft_printunumber(num % 10);
	}
	return (count);
}
