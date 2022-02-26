/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:29 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/26 19:47:00 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_small(int size, t_list **headA, t_list **tailA)
{
	if (size == 1)
		exit (0);
	else if (size == 2)
		sort_two(headA);
	else if (size == 3)
		sort_three(headA, tailA);
	else if (size == 4)
		sort_four(headA, tailA);
	else if (size == 5)
		sort_five(headA, tailA);
}

void	sort_two(t_list **head)
{
	if ((*head)-> content > (*head)-> next -> content)
		(*head) = swap (*head);
}

void	sort_three(t_list **head, t_list **tail)
{
	int		h;
	int		s;
	int		t;

	h = (*head)-> content;
	s = (*head)-> next -> content;
	t = (*tail)-> content;
	if (h > s && s < t && h < t)
		(*head) = swap (*head);
	else if (h > s && s > t)
	{
		(*head) = swap (*head);
		reverse_rotate_a(head, tail);
	}
	else if (h > s && s < t && h > t)
		rotate_a(head, tail);
	else if (h < s && s > t && h < t)
	{
		(*head) = swap(*head);
		rotate_a(head, tail);
	}
	else if (h < s && s > t && h > t)
		reverse_rotate_a(head, tail);
}

void	sort_four(t_list **headA, t_list **tailA)
{
	t_list	*temp;
	t_list	*min;
	t_list	*head_b;

	min = (*headA);
	temp = (*headA)->next;
	head_b = NULL;
	while (temp)
	{
		if (min -> content > temp -> content)
		{
			min = temp;
			temp = temp-> next;
		}
		else
			temp = temp -> next;
	}
	while ((*headA)-> content != min -> content)
		reverse_rotate_a(headA, tailA);
	push_b(headA, &head_b);
	sort_three(headA, tailA);
	push_a(headA, &head_b);
}
