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

void	sort_B(t_list **headA, t_list **headB, t_list **tailB)
{
	t_list	*temp;
	t_list	*move;
	int		i;
	int		big;
	//t_list	*printB;

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
				rotateB(headB, tailB);	
			pushA(headA, headB);
		}
		else
		{
			while ((*headB) -> content != big)
				reverse_rotateB(headB,tailB);
			pushA(headA, headB);
		}
	}
}



/*void	sort_hundred(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int m, int n)
{
	int	i;
	int	j;
	//t_list	**tailB = NULL;
	t_list	*temp;

	i = numbers_to_push(n);
	temp = (*headA);
	while(i)
	{
		if ((*headA) -> content >= m)
		{
			pushB(headA, headB);
			i--;
		}
		else
			reverse_rotateA(headA, tailA);
	}
	(*tailB) = ft_lstlast(*headB);
	sort_B(headA, headB, tailB);
	i = numbers_to_push(n);
	j = n - i;
	while(j)
	{
		if((*headA) -> content < m)
		{
			pushB(headA, headB);
			j--;
		}
		else
			reverse_rotateA(headA, tailA);
	}
	(*tailB) = ft_lstlast(*headB);
	sort_B(headA, headB, tailB);
}*/

void	push_big(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	//printf("La N es: %d\n", n);
	j = numbers_to_push(n);
	//printf("J : %d\n", j);
	temp = (*headA);
	while (j)
	{
		//printf("La Q2 es: %d\n", q);
		if((temp -> content) >= q)
		{
			//printf("headA = %d\n", (*headA) -> content);
			//printf("temp = %d\n", temp -> content);
			i = smart_rotate((*headA), temp);
			//printf("smart rotate big = %d\n", i);
			big = temp -> content;
			if (i == 1)
			{
				temp = temp -> next;
				while ((*headA) -> content != big)
					rotateA(headA, tailA);
				pushB(headA, headB);
				j--;
				//printf("La J es: %d\n", j);
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

void	push_small(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;
	//t_list	*printB;

	temp = (*headA);
	j = (n - numbers_to_push(n))/2;
	//printf("La J es: %d\n", j);
	while (j)
	{
		if(temp -> content < q)
		{
			i = smart_rotate((*headA), temp);
			//printf("smart rotate small: %d\n", i);
			big = temp -> content;
			if (i == 1)
			{
				while ((*headA) -> content != big)
					rotateA(headA, tailA);
				pushB(headA, headB);
				temp = (*headA);
				j--;
			}
			else
			{
				while ((*headA) -> content != big)
					reverse_rotateA(headA,tailA);
				pushB(headA, headB);
				temp = (*headA);
				j--;
			}
		}
		else
			temp = temp -> next;
	}
	(*tailB) = ft_lstlast(*headB);
	sort_B(headA, headB, tailB);
}

void	push_medium(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q, int q2, int n)
{
	t_list	*temp;
	int		i;
	int		big;
	int		j;

	//printf("La Q es: %d\n", q);
	j = (n - numbers_to_push(n))/2;	
	temp = (*headA);
	while (j)
	{
		//printf("temp content: %d\n", temp -> content);
		if((temp -> content) < (q2) && (temp -> content) >= q)
		{
			//printf("headA = %d\n", (*headA) -> content);
			//printf("temp = %d\n", temp -> content);
			i = smart_rotate((*headA), temp);
			//printf("smart rotate big = %d\n", i);
			big = temp -> content;
			if (i == 1)
			{
				temp = temp -> next;
				while ((*headA) -> content != big)
					rotateA(headA, tailA);
				pushB(headA, headB);
				j--;
				//printf("La J es: %d\n", j);
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
	push_small(headA, headB, tailA, tailB, q, n);
}

