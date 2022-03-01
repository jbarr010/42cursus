/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:55:00 by jbarredo          #+#    #+#             */
/*   Updated: 2022/03/01 13:59:11 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_hundred(t_list **headA, t_list **tailA,
			t_list **head_b, t_list **tail_b)
{
	push_big(headA, head_b, tailA, tail_b);
	push_med(headA, head_b, tailA, tail_b);
}

int	smart_rotate(t_list *head, t_list *num)
{
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	j = 0;
	temp = head;
	while (temp != num)
	{
		temp = temp->next;
		i++;
	}
	temp = num;
	while (temp != NULL)
	{
		temp = temp -> next;
		j++;
	}
	if (i <= j)
		return (1);
	else
		return (2);
}

int	numbers_to_push(int n)
{
	int	i;

	if ((n % 3) != 0)
		i = (n / 3) + 1;
	else
		i = n / 3;
	return (i);
}

void	sort_b(t_list **headA, t_list **headB, t_list **tailB)
{
	t_list	*temp;
	int		i;
	int		big;

	while (*headB)
	{
		temp = find_max(headB);
		big = temp -> content;
		i = smart_rotate((*headB), temp);
		if (i == 1)
		{
			while ((*headB)-> content != big)
				rotate_b(headB, tailB);
			push_a(headA, headB);
		}
		else
		{
			while ((*headB)-> content != big)
				reverse_rotate_b(headB, tailB);
			push_a(headA, headB);
		}
	}
}

t_list	*find_max(t_list **headB)
{
	t_list	*temp;
	t_list	*move;
	int		max;

	max = 0;
	temp = (*headB);
	move = temp -> next;
	while (move)
	{
		if (move -> content > temp -> content)
		{
			temp = move;
			move = temp -> next;
		}
		else
			move = move -> next;
	}
	return (temp);
}
