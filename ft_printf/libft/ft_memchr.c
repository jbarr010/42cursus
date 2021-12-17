/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:54:15 by jbarredo          #+#    #+#             */
/*   Updated: 2021/08/18 17:45:56 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	charachter;
	size_t			i;

	str = (unsigned char *)s;
	charachter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == charachter)
		{
			return (str);
		}
		str++;
		i++;
	}
	return (NULL);
}
