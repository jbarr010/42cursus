/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:05:37 by jbarredo          #+#    #+#             */
/*   Updated: 2021/08/20 16:46:26 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (n[0] == '\0')
		return ((char *)h);
	i = 0;
	while (h[i] && i < len)
	{
		if (h[i] == n[0])
		{
			j = 0;
			while (h[i + j] == n[j] && i + j < len)
			{
				if (n[j + 1] == '\0')
					return ((char *)&h[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
