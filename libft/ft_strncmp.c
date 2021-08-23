/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:48:36 by jbarredo          #+#    #+#             */
/*   Updated: 2021/08/18 16:51:46 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	sc;

	sc = 0;
	while (sc < n && (s1[sc] && s2[sc]))
	{
		if (s1[sc] != s2[sc])
			return ((unsigned char)s1[sc] - (unsigned char)s2[sc]);
		sc++;
	}
	if (sc < n && ((s1[sc] == '\0' && s2[sc] != '\0') || \
				(s1[sc] != '\0' && s2[sc] == '\0')))
		return ((unsigned char)s1[sc] - (unsigned char)s2[sc]);
	return (0);
}
