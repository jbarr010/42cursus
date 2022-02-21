/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:43:56 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/15 19:54:35 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		n;
	int		size;
	t_list	*headA;
	t_list	*tailA;

	headA = NULL;
	if (argc <= 1)
		return(0);
	n = argc - 1;
	if(check_char(n, argv))
	{
		if (argc == 2)
			headA =	list_parm(argv);
		else if (argc > 2)
			headA = list_simple(n, argv);
		tailA = ft_lstlast(headA);
		size = lstsize(headA);
		if (size <= 5)
			sort_small(size, &headA, &tailA);
		else if (size > 5 && size <= 100)
		{
			sort_hundred(&headA, &tailA, n);
		}
		else if (size > 100 && size <= 500)
		{
			sort_500(&headA, &tailA, n);
		}
	}
	else
		write (1, "Error\n", 6) ;
	return (0);
}
