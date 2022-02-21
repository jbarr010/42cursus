/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:02:49 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/08 17:35:50 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int		s;
	int		m;
	long	sol;

	s = 0;
	m = 1;
	sol = 0;
	while (str[s] && (str[s] == '\t' || str[s] == '\r' || str[s] == ' '
			||str[s] == '\f' || str[s] == '\v' || str[s] == '\n'))
		s++;
	if (str[s] == '+' || str[s] == '-')
	{
		if (str[s] == '-')
			m *= -1;
		s++;
	}
	while (str[s] >= '0' && str[s] <= '9')
	{
		sol = (str[s] - '0') + (sol * 10);
		if ((sol * m < -2147483648) || (sol * m > 2147483648))
			return ((sol * m < -2147483648) - 1);
		s++;
	}
	return (sol * m);
}

int	ft_atoi_error(char *str)
{
	int		s;
	int		m;
	long	sol;

	s = 0;
	m = 1;
	sol = 0;
	while (str[s] && (str[s] == '\t' || str[s] == '\r' || str[s] == ' '
			||str[s] == '\f' || str[s] == '\v' || str[s] == '\n'))
		s++;
	if (str[s] == '+' || str[s] == '-')
	{
		if (str[s] == '-')
			m *= -1;
		s++;
	}
	while (str[s] >= '0' && str[s] <= '9')
	{
		sol = (str[s] - '0') + (sol * 10);
		if ((sol * m < -2147483648) || (sol * m > 2147483647))
			return (0);
		s++;
	}
	return (1);
}


int	*fill_stack(int n, char **parm)
{
	int	*stack;
	int	i;

	stack = malloc(sizeof(int) * n);
	i = n - 1;
	while(i >= 0)
	{
		if (ft_atoi_error(parm[i + 1]))
		{
			stack[i] = ft_atoi(parm[i + 1]);
			i--;
		}
		else
		{
			write (1, "Error\n", 6);
			exit(0);
		}
	}
	return (stack);
}

int	*fill_parm(int i, char **str)
{
	int	*stack;
	int	n;

	stack = malloc(sizeof(int) * i);
	n = i - 1;
	while(n >= 0)
	{
		if (ft_atoi_error(str[n]))
		{
			stack[n] = ft_atoi(str[n]);
			n--;
		}
		else
		{
			write (1, "Error\n", 6);
			exit (0);
		}
	}
	return (stack);
}

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

int	ft_strlen(const char *str)
{
	size_t	num;

	num = 0;
	while (str[num] != '\0')
	{
		num++;
	}
	return (num);
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
