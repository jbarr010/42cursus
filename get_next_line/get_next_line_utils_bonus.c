#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

size_t	len_key(char *str, char key)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != key)
		i++;
	return (i);
}

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
