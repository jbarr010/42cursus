/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:11:01 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/27 21:28:10 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static char	**ft_freemem(char **f, size_t i)
{
	size_t	j;

	if (f)
	{
		j = 0;
		while (j < i)
		{
			if (f[j] != NULL)
				free (f[i]);
			i++;
		}
		free (f);
	}
	return (NULL);
}

static size_t	ft_cwords(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	if (s[i - 1] == c)
		count--;
	return (count);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

static char	**fill_gaps(char **dest, const char *str, char to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*str != '\0')
	{
		while (*str == to_find && *str != '\0')
			str++;
		if (*str == '\0')
			continue ;
		dest[i] = malloc(sizeof(char) * ft_wordlen(str, to_find) + 1);
		if (dest[i] == NULL)
			return (ft_freemem(dest, i));
		j = 0;
		while (*str != to_find && *str != '\0')
		{
			dest[i][j] = *str;
			j++;
			str++;
		}
		dest[i][j] = '\0';
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) > 0)
		dest = malloc(sizeof(char *) * (ft_cwords(s, c) + 1));
	else
		dest = malloc(sizeof(char *) * (0 + 1));
	if (dest == NULL)
		return (NULL);
	fill_gaps(dest, s, c);
	return (dest);
}
