/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:43:56 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/28 00:01:54 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		//printf("%d\n", tmp->content);
		tmp = tmp->next;
		free(*lst);
		*lst = tmp;
	}
}

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
		if (is_sorted(head_a))
			size_choose(head_a, tail_a, size);
		return (0);
	}
	else
		write (1, "Error\n", 6);
	return (0);
}

void	size_choose(t_list *head_a, t_list *tail_a, int size)
{
	t_list  *head_b;
	t_list  *tail_b;
	
	head_b = NULL;
	tail_b = NULL;
	if (size <= 5)
		sort_small(size, &head_a, &tail_a);
	else if (size > 5 && size <= 99)
		sort_rest(&head_a, &tail_a, head_b, tail_b);
	else if (size == 100)
		sort_hundred(&head_a, &tail_a);
	else if (size > 100 && size <= 499)
		sort_rest(&head_a, &tail_a, head_b, tail_b);
	else if (size == 500)
		sort_500(&head_a, &tail_a);
	ft_lstclear(&head_a);
	ft_lstclear(&head_b);
	//ft_lstclear(&tail_a);
	//ft_lstclear(&tail_b);
}
