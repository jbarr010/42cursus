/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:47:27 by jbarredo          #+#    #+#             */
/*   Updated: 2021/08/17 13:44:59 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*temp;

	i = 0;
	temp = s;
	if (n > 0)
	{
		while (n > 0)
		{
			temp[i] = '\0';
			i++;
			n--;
		}
	}
}
