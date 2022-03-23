/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:44:13 by jbarredo          #+#    #+#             */
/*   Updated: 2022/03/20 13:52:53 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

char	**create_char(char *str)
{
	char	**map_char;
	char		*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = str;
	while (str[i])
	{
		if (str[i] == '\n')
			i++;
		else
		{
			aux[j] = str[i];
			i++;
			j++;
		}
	}
	map_char = ft_split(aux, 32);
	free(str);
	return (map_char);
}

int	file_len(char *name)
{
	char	*str;
	int		len;
	int		n;
	int		fd;

	len = 0;
	n = 0;
	while (len == n)
	{
		n++;
		fd = open(name, O_RDONLY);
		str = malloc(sizeof(char) * n);
		len = read(fd, str, n);
		close(fd);
	}
	free(str);
	return (len);
}

char	*read_file(char *argv)
{
	int		fd;
	int		len;
	char		*str;
	int		rd;

	rd = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	len = file_len(argv);
	str = malloc(sizeof(char) * len);
	rd = read(fd, str, len);
	close(fd);
	return (str);
}

int	get_x(char *str)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == ' ')
		{
			x++;
			i++;
		}
		else
			i++;
	}
	return (x);
}

int	get_y(char *str)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			y++;
			i++;
		}
		else
			i++;
	}
	return (y);
}

int	**create_int(char **map_char, int x, int y)
{
	int	**matrix;
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	matrix = (int **)malloc(sizeof(int *) * (y));
	while (i < y)
	{
		matrix[i] = (int *)malloc(sizeof(int) * (x));
		i++;
	}
	j = 0;
	i = 0;
	while (n < (y * x))
	{
		while (i < x)
		{
			matrix[j][i] = ft_atoi(map_char[n]);
			n++;
			i++;
		}
		j++;
		i = 0;
	}
	return (matrix);
}

int	main(int argc, char **argv)
{
	char	**map_char;
	int		i;
	int		j;
	int		x;
	int		y;
	int		**map_int;
	char		*str;

	i = 0;
	j = 0;
	if (argc != 2)
		return (0);
	str = read_file(argv[1]);
	x = get_x(str);
	y = get_y(str);
	map_char = create_char(str);
	printf("La X es: %d\n", x);
	printf("La Y es: %d\n", y);
	map_int = create_int(map_char, x, y);
	i = 0;
	while (j < y)
	{
		while (i < x)
		{
			printf("%d\t", map_int[j][i]);
			i++;
		}
		printf("\n");
		j++;
		i = 0;
	}
	return (0);
}
