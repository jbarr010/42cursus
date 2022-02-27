/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:20 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/27 14:39:55 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_500(t_list **headA, t_list **tailA)
{
	t_list	*head_b;
	t_list	*tail_b;

	head_b = NULL;
	tail_b = NULL;
	push_5(headA, &head_b, tailA, &tail_b);
	push_3(headA, &head_b, tailA, &tail_b);
	push_2(headA, &head_b, tailA, &tail_b);
}

int	numbers_to_push_500(int n)
{
	int	i;

	if ((n % 5) != 0)
		i = (n / 5) + 1;
	else
		i = n / 5;
	return (i);
}

void	push_5(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		n;
	int		q4;

	n = lstsize(*headA);
	j = numbers_to_push_500(n);
	temp = (*headA);
	q4 = q_value_4(*headA);
	while (j)
	{
		if ((temp -> content) >= q4)
		{
			temp = ask_push(headA, headB, temp, tailA);
			j--;
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_b(headA, headB, tailB);
	push_4(headA, headB, tailA, tailB);
}

void	push_4(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		n;
	int		q3;
	int		q4;

	n = lstsize(*headA);
	j = (n - numbers_to_push_500(n)) / 4;
	temp = (*headA);
	q4 = q_value_4(*headA);
	q3 = q_value_3(*headA);
	while (j)
	{
		if ((temp -> content) < (q4) && (temp -> content) >= q3)
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

void	push_3(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		n;
	int		q3;
	int		q2;

	n = lstsize(*headA);
	j = (n - numbers_to_push_500(n)) / 4;
	temp = (*headA);
	q3 = q_value_3(*headA);
	q2 = q_value_2(*headA);
	while (j)
	{
		if ((temp -> content) < (q3) && (temp -> content) >= q2)
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
