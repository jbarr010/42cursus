/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:38:32 by jbarredo          #+#    #+#             */
/*   Updated: 2021/11/10 17:12:00 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printnumbers(int num)
{
	char	*result;
	int		count;

	result = ft_itoa(num);
	count = 0;
	while (result[count] != '\0')
	{
		ft_putchar_fd(result[count], 1);
		count++;
	}
	free (result);
	return (count);
}
