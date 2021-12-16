/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:20:44 by jbarredo          #+#    #+#             */
/*   Updated: 2021/09/07 18:02:34 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (start > n)
		return (ft_strdup(""));
	if (len > n)
		len = n;
	res = (char *)malloc(sizeof(*s) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			res[j++] = s[i];
	}
	res[j] = '\0';
	return (res);
}
