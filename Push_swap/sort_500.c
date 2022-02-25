/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:20 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/15 19:54:25 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_500(t_list **headA, t_list **tailA, int n)
{
	t_list	*headB;
	t_list	*tailB;
	int	q1;
	int	q2;
	int	q3;
	int	q4;

	headB = NULL;
	tailB = NULL;
	q1 = q_value_1(*headA);
	q2 = q_value_2(*headA);
	q3 = q_value_3(*headA);
	q4 = q_value_4(*headA);
	push_5(headA, &headB, tailA, &tailB, q3, q4, n);
	push_3(headA, &headB, tailA, &tailB, q2, q3, n);
	push_2(headA, &headB, tailA, &tailB, q1, q2, n);
}

int	numbers_to_push_500(int	n)
{
	int	i;

	if ((n%5) != 0)
		i = (n/5) + 1;
	else
		i = n/5;
	return(i);
}

void	push_5(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q3, int q4, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	j = numbers_to_push_500(n);	
	temp = (*headA);
	while (j)
	{
		if((temp -> content) >= q4)
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
	push_4(headA, headB, tailA, tailB, q3, q4, n);
}

void	push_4(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q3, int q4, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	j = (n - numbers_to_push_500(n))/4;
	temp = (*headA);
	while (j)
	{
		if((temp -> content) < (q4) && (temp -> content) >= q3)
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
}

void	push_3(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q2, int q3, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	j = (n - numbers_to_push_500(n))/4;
	temp = (*headA);
	while (j)
	{
		if((temp -> content) < (q3) && (temp -> content) >= q2)
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
}

void	push_2(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q1, int q2, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	j = (n - numbers_to_push_500(n))/4;
	temp = (*headA);
	while (j)
	{
		if((temp -> content) < (q2) && (temp -> content) >= q1)
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
	push_1(headA, headB, tailA, tailB, q1, n);
}

void	push_1(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q1, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	j = (n - numbers_to_push_500(n))/4;
	temp = (*headA);
	while (j)
	{
		if((temp -> content) < q1)
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
}
