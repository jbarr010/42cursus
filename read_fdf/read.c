/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:44:13 by jbarredo          #+#    #+#             */
/*   Updated: 2022/03/19 20:30:43 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

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

char	**create_char(char *argv)
{
	int		fd;
	char	**map_char;
	int		len;
	char	*str;
	int		rd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	len = file_len(argv);
	str = malloc(sizeof(char) * len);
	rd = read(fd, str, len);
	map_char = ft_split(str, 32);
	free(str);
	close(fd);
	return (map_char);
}

int	get_x(char **map_char)
{
	int	x;

	x = 0;
	while (map_char[x][0] != '\n')
		x++;
	return (x);
}

int	get_y(char **map_char)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map_char[i] != NULL)
	{
		if (map_char[i][0] == '\n')
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
		//printf("X de malloc: %d\n", x);
		matrix[i] = (int *)malloc(sizeof(int) * x);
		i++;
	}
	while (n < y)
	{
		if (map_char[n][0] == '\n')
		{
			j++;
			i = 0;
			n++;
		}
		else
		{
			matrix[j][i] = ft_atoi(map_char[n]);
			n++;
			i++;
		}
	}
	//matrix[j] = '\0';
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

	i = 0;
	j = 0;
	if (argc != 2)
		return (0);
	map_char = create_char(argv[1]);
	while (map_char[i])
	{
		printf("MAP CHAR : %s\n", map_char[i]);
		i++;
	}
	x = get_x(map_char);
	y = get_y(map_char);
	printf("La X es: %d\n", x);
	printf("La Y es: %d\n", y);
	map_int = create_int(map_char, x, y);
	while (j < y)
	{
		while (i < x)
		{
			printf("%d ' '", map_int[j][i]);
			i++;
		}
		printf("\n");
		j++;
		i = 0;
	}
	return (0);
}
