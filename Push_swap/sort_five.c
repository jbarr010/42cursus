/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:58:51 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/27 21:45:10 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	prepare_five(t_list **headA, t_list **headB, t_list **tailA, int m)
{
	int	i;

	i = 2;
	while (i)
	{
		if ((*headA)-> content <= m)
		{
			push_b(headA, headB);
			i--;
		}
		else
			reverse_rotate_a(headA, tailA);
	}
}

void	sort_five(t_list **headA, t_list **tailA)
{
	int		m;
	t_list	*head_b;

	head_b = NULL;
	m = auxiliar(*headA);
	prepare_five(headA, &head_b, tailA, m);
	sort_three(headA, tailA);
	if ((head_b)-> content < (head_b)-> next -> content)
	{
		(head_b) = swap_b(head_b);
		push_a(headA, &head_b);
		push_a(headA, &head_b);
	}
	else
	{
		push_a(headA, &head_b);
		push_a(headA, &head_b);
	}
}
