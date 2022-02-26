/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:45:55 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/26 22:47:19 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	push_2(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		n;
	int		q1;
	int		q2;

	n = lstsize(*headA);
	j = (n - numbers_to_push_500(n)) / 4;
	temp = (*headA);
	q2 = q_value_2(*headA);
	q1 = q_value_1(*headA);
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
	push_1(headA, headB, tailA, tailB);
}

void	push_1(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB)
{
	t_list	*temp;
	int		j;
	int		n;
	int		q1;

	n = lstsize(*headA);
	j = (n - numbers_to_push_500(n)) / 4;
	temp = (*headA);
	q1 = q_value_1(*headA);
	while (j)
	{
		if ((temp -> content) < q1)
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
