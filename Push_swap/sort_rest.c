/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:35:02 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/25 21:47:28 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_rest(t_list **headA, t_list **tailA, int n)
{
	t_list	*headB;
	t_list	*tailB;
	int	m;

	headB = NULL;
	tailB = NULL;
	m = m_value(*headA);
	push_rest(headA, &headB, tailA, &tailB, m, n);
}

int	numbers_to_push_rest(int n)
{
	int	i;

	if ((n%2) != 0)
		i = (n/2) + 1;
	else
		i = n/2;
	return(i);
}

void	push_rest_2(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int m, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	temp = (*headA);
	j = (n - numbers_to_push_rest(n));
	while (j)
	{
		if(temp -> content < m)
		{
			i = smart_rotate((*headA), temp);
			big = temp -> content;
			if (i == 1)
			{
				while ((*headA) -> content != big)
					rotate_a(headA, tailA);
				push_b(headA, headB);
				temp = (*headA);
				j--;
			}
			else
			{
				while ((*headA) -> content != big)
					reverse_rotate_a(headA,tailA);
				push_b(headA, headB);
				temp = (*headA);
				j--;
			}
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_b(headA, headB, tailB);
}

void	push_rest(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int m, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	j = numbers_to_push_rest(n);	
	temp = (*headA);
	while (j)
	{
		if((temp -> content) >= m)
		{
			i = smart_rotate((*headA), temp);
			big = temp -> content;
			if (i == 1)
			{
				temp = temp -> next;
				while ((*headA) -> content != big)
					rotate_a(headA, tailA);
				push_b(headA, headB);
				j--;
			}
			else
			{
				temp = temp -> next;
				while ((*headA) -> content != big)
					reverse_rotate_a(headA,tailA);
				push_b(headA, headB);
				j--;
			}
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_b(headA, headB, tailB);
	push_rest_2(headA, headB, tailA, tailB, m, n);
}
