/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:43:56 by jbarredo          #+#    #+#             */
/*   Updated: 2022/01/12 22:00:39 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		n;
	int		*A;
	char	**str;
	int		i;

	if (argc <= 1)
	{
		printf("%s", "donde estan los tios???");
		return(0);
	}
	n = argc - 1;	
	if(check_char(n, argv))
	{
		if (argc == 2)
		{
			str = ft_split(argv[1], 32);
			i = 0;
			while(str[i])
				i++;
			A = fill_parm(i, str);
			if (check_rep(i, A))
			{
				print_parm(A);
				ft_arrtolist(i, A);
			}
			else
			{
				printf("%s\n", "se repite");
				return (0);
			}
		}
		if (argc > 2)
		{
			A = fill_stack(n, argv);
			if(check_rep(n, A))
			{
				print_stack(A);
				printf("%s", "todo bien\n");
				ft_arrtolist(n, A);
				printf("%s", "hago listas porque soy muy listo\n");	
			}	
			else
				printf("%s", "\033[0;31mERROR REP\n\033[0m");
		}
	}
	else
		printf("%s", "\033[0;31mERROR CHAR\n\033[0m");
	return (0);
}
