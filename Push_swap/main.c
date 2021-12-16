/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:43:56 by jbarredo          #+#    #+#             */
/*   Updated: 2021/12/16 20:31:13 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;
	size_t	size;

	size = 0;
	while (s1[size] != '\0')
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}



int	main(int argc, char **argv)
{
	int		n;
	int		*A;

	if (argc <= 1)
		return(0);
	n = argc - 1;
	if(check_char(n, argv))
	{
		A = fill_stack(n, argv);
		print_stack(A, n);
	}
	else
		printf("%s", "\033[0;31mERROR\n\033[0m");
	return (0);
}
