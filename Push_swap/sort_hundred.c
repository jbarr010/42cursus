/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:35:02 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/27 23:37:54 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "push_swap.h"

void	push_big(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		n;
	int		q2;

	q2 = q_value(*headA);
	n = lstsize(*headA);
	j = numbers_to_push(n);
	temp = (*headA);
	while (j)
	{
		if ((temp -> content) >= q2)
		{
			temp = ask_push(headA, headB, temp, tailA);
			j--;
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_b(headA, headB, tailB);
}

t_list	*ask_push(t_list **headA, t_list **headB, t_list *temp, t_list **tailA)
{
	int	i;
	int	big;

	i = smart_rotate((*headA), temp);
	big = temp -> content;
	if (i == 1)
	{
		temp = temp -> next;
		while ((*headA)-> content != big)
			rotate_a(headA, tailA);
		push_b(headA, headB);
	}
	else
	{
		temp = temp -> next;
		while ((*headA)-> content != big)
			reverse_rotate_a(headA, tailA);
		push_b(headA, headB);
	}
	return (temp);
}

void	push_sm(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		q1;
	int		n;

	q1 = auxiliar(*headA);
	n = lstsize(*headA);
	temp = (*headA);
	j = (n - numbers_to_push(n)) / 2;
	while (j)
	{
		if (temp -> content < q1)
		{
			temp = ask_push(headA, headB, temp, tailA);
			j--;
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_b(headA, headB, tailB);
}

void	push_med(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		n;
	int		q1;
	int		q2;

	q1 = auxiliar(*headA);
	q2 = q_value(*headA);
	n = lstsize(*headA);
	j = (n - numbers_to_push(n)) / 2;
	temp = (*headA);
	while (j)
	{
		if ((temp -> content) < (q2) && (temp -> content) >= q1)
		{
			temp = ask_push(headA, headB, temp, tailA);
			j--;
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_b(headA, headB, tailB);
	push_sm(headA, headB, tailA, tailB);
}
