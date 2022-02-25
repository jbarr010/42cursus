/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:35:02 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/15 19:29:40 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hundred(t_list **headA, t_list **tailA, int n)
{
	t_list	*headB;
	t_list	*tailB;
	int	q1;
	int	q2;

	headB = NULL;
	tailB = NULL;
	q1 = auxiliar(*headA);
	q2 = q_value(*headA);
	push_big(headA, &headB, tailA, &tailB, q2, n);
	push_medium(headA, &headB, tailA, &tailB, q1, q2,n);
}


int	smart_rotate(t_list *head, t_list *num)
{
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	j = 0;
	temp = head;
	while(temp != num)
	{
		temp = temp->next;
		i++;
	}
	temp = num;
	while(temp != NULL)
	{
		temp = temp -> next;
		j++;
	}
	if (i <= j)
		return(1);
	else
		return(2);
}


int	numbers_to_push(int	n)
{
	int	i;

	if ((n%3) != 0)
		i = (n/3) + 1;
	else
		i = n/3;
	return(i);
}

void	sort_b(t_list **headA, t_list **headB, t_list **tailB)
{
	t_list	*temp;
	t_list	*move;
	int		i;
	int		big;

	while (*headB)
	{
		temp = (*headB);
		move = temp -> next;
		while (move)
		{
			if(move -> content > temp -> content)
			{
				temp = move;
				move = temp -> next;
			}
			else
				move = move -> next;
		}
		big = temp -> content;
		i = smart_rotate((*headB), temp);	
		if (i == 1)
		{
			while ((*headB) -> content != big)
				rotate_b(headB, tailB);	
			push_a(headA, headB);
		}
		else
		{
			while ((*headB) -> content != big)
				reverse_rotate_b(headB,tailB);
			push_a(headA, headB);
		}
	}
}

void	push_big(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	j = numbers_to_push(n);
	temp = (*headA);
	while (j)
	{
		if((temp -> content) >= q)
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

void	push_small(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	temp = (*headA);
	j = (n - numbers_to_push(n))/2;
	while (j)
	{
		if(temp -> content < q)
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

void	push_medium(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q, int q2, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	j = (n - numbers_to_push(n))/2;	
	temp = (*headA);
	while (j)
	{
		if((temp -> content) < (q2) && (temp -> content) >= q)
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
	push_small(headA, headB, tailA, tailB, q, n);
}
