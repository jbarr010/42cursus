/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:32:00 by jbarredo          #+#    #+#             */
/*   Updated: 2021/11/22 20:27:36 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

//char	*ft_alloc(int buffer)
//{
//	char	*cache;

//	cache = malloc((buffer + 1) * sizeof(char));
//	if (!cache)
//		return (NULL);
//	else
//		return (cache);
//}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*read_str(int fd, char *str)
{
	char	*buff;
	int		rd;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	line[i++] = '\0';
	return (line);
}

char	*next_line(char *str)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	next = (char *)malloc((sizeof(char) * ft_strlen(str - i) + 1));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		next[j++] = str[i++];
	next[j] = '\0';
	free(str);
	return (next);
}

/*char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[j++] = s2[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	result = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		result[j++] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		result[j++] = s2[i];
	result[j] = '\0';
	free ((char *)s1);
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (s1[len] != '\0')
		len++;
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		result[i] = s1[i];
	result[i] = '\0';
	return (result);
}
