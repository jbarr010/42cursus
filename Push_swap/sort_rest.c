/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:35:02 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/27 13:54:50 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_rest(t_list **headA, t_list **tailA)
{
	t_list	*head_b;
	t_list	*tail_b;

	head_b = NULL;
	tail_b = NULL;
	push1(headA, &head_b, tailA, &tail_b);
}

int	numbers_to_push_rest(int n)
{
	int	i;

	if ((n % 2) != 0)
		i = (n / 2) + 1;
	else
		i = n / 2;
	return (i);
}

void	push2(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		n;
	int		m;

	n = lstsize(*headA);
	m = m_value(*headA);
	temp = (*headA);
	j = (n - numbers_to_push_rest(n));
	while (j)
	{
		if (temp -> content < m)
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

void	push1(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		n;
	int		m;

	n = lstsize(*headA);
	m = m_value(*headA);
	j = numbers_to_push_rest(n);
	temp = (*headA);
	while (j)
	{
		if ((temp -> content) >= m)
		{
			temp = ask_push(headA, headB, temp, tailA);
			j--;
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_b(headA, headB, tailB);
	push2(headA, headB, tailA, tailB);
}
