/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:43:56 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/26 22:39:13 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		n;
	int		size;
	t_list	*head_a;
	t_list	*tail_a;

	head_a = NULL;
	if (argc <= 1)
		return (0);
	n = argc - 1;
	if (check_char(n, argv))
	{
		if (argc == 2)
			head_a = list_parm(argv);
		else if (argc > 2)
			head_a = list_simple(n, argv);
		tail_a = ft_lstlast(head_a);
		size = lstsize(head_a);
		size_choose(head_a, tail_a, n, size);
	}
	else
		write (1, "Error\n", 6);
	return (0);
}

void	size_choose(t_list *head_a, t_list *tail_a, int n, int size)
{
	if (size <= 5)
		sort_small(size, &head_a, &tail_a);
	else if (size > 5 && size <= 99)
		sort_rest(&head_a, &tail_a, n);
	else if (size == 100)
		sort_hundred(&head_a, &tail_a);
	else if (size > 100 && size <= 499)
		sort_rest(&head_a, &tail_a, n);
	else if (size == 500)
		sort_500(&head_a, &tail_a);
}
