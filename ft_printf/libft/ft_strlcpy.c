/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:59:02 by jbarredo          #+#    #+#             */
/*   Updated: 2021/08/17 18:53:42 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t ds)
{
	unsigned int		i;
	size_t				j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (ds)
	{
		while ((ds - 1) > j && src[j])
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}
