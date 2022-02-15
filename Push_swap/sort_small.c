/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:29 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/14 22:24:03 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **head, t_list **tail)
{
	int		h;
	int		s;
	int		t;

	h = (*head) -> content;
	s = (*head) -> next -> content;
	t = (*tail) -> content;
	if (h > s && s < t && h < t)
		(*head) = swap (*head);
	else if (h > s && s > t)
	{
		(*head) = swap (*head);
		reverse_rotateA(head, tail);
	}
	else if (h > s && s < t && h > t)
		rotateA(head, tail);
	else if (h < s && s > t && h < t)
	{
		(*head) = swap(*head);	
		rotateA(head, tail);
	}
	else if (h < s && s > t && h > t)
		reverse_rotateA(head, tail);
}

void	prepare_five(t_list **headA, t_list **headB, t_list **tailA, int m)
{
	int	i;

	i = 2;
	while(i)
	{
		if((*headA) -> content < m)
		{
			pushB(headA, headB);
			i--;
		}
		else
			reverse_rotateA(headA, tailA);
	}
}

void	sort_five(t_list **headA, t_list **headB, t_list **tailA, int m)
{
	prepare_five(headA, headB, tailA, m);
	sort_three(headA, tailA);
	if ((*headB) -> content < (*headB) -> next -> content)
	{
		(*headB) = swapB(*headB);
		pushA(headA, headB);
		pushA(headA, headB);
	}
	else
	{
		pushA(headA, headB);
		pushA(headA, headB);
	}
}
