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
					rotateA(headA, tailA);
				pushB(headA, headB);
				j--;
			}
			else
			{
				temp = temp -> next;
				while ((*headA) -> content != big)
					reverse_rotateA(headA,tailA);
				pushB(headA, headB);
				j--;
			}
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_B(headA, headB, tailB);
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
					rotateA(headA, tailA);
				pushB(headA, headB);
				j--;
			}
			else
			{
				temp = temp -> next;
				while ((*headA) -> content != big)
					reverse_rotateA(headA,tailA);
				pushB(headA, headB);
				j--;
			}
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_B(headA, headB, tailB);
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
					rotateA(headA, tailA);
				pushB(headA, headB);
				j--;
			}
			else
			{
				temp = temp -> next;
				while ((*headA) -> content != big)
					reverse_rotateA(headA,tailA);
				pushB(headA, headB);
				j--;
			}
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_B(headA, headB, tailB);
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
					rotateA(headA, tailA);
				pushB(headA, headB);
				j--;
			}
			else
			{
				temp = temp -> next;
				while ((*headA) -> content != big)
					reverse_rotateA(headA,tailA);
				pushB(headA, headB);
				j--;
			}
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_B(headA, headB, tailB);
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
					rotateA(headA, tailA);
				pushB(headA, headB);
				j--;
			}
			else
			{
				temp = temp -> next;
				while ((*headA) -> content != big)
					reverse_rotateA(headA,tailA);
				pushB(headA, headB);
				j--;
			}
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_B(headA, headB, tailB);
}

