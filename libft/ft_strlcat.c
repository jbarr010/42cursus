/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:54:52 by jbarredo          #+#    #+#             */
/*   Updated: 2021/08/17 20:09:08 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t ds)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	j = dlen;
	if (ds <= dlen)
		return (ds + slen);
	while (ds - 1 > dlen && src[i])
	{
		dst[dlen] = src[i];
		dlen++;
		i++;
	}
	dst[dlen] = '\0';
	return (j + slen);
}
