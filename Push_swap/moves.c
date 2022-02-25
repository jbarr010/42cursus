/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:12:13 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/15 17:34:46 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

//swap: Intercambia las dos primeras posiciones
t_list	*swap(t_list *head)
{
	t_list	*temp;
	t_list	*second;
	int		temp1;
	int		temp2;
	
	temp = NULL;
	second = NULL;
	temp1 = head -> content;
	second  = head -> next;
	temp2 = second ->content;
	second ->content = temp1;
	head -> content = temp2;
	write(1, "sa\n", 3);
	return (head);
}

t_list	*swap_b(t_list *head)
{
	t_list	*temp;
	t_list	*second;
	int		temp1;
	int		temp2;

	temp = NULL;
	second = NULL;
	temp1 = head -> content;
	second  = head -> next;
	temp2 = second ->content;
	second ->content = temp1;
	head -> content = temp2;
	write(1, "sb\n", 3);
	return (head);
}


t_list	*ft_lstlast(t_list *head)
{
	t_list	*last;

	last = head;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}
void	ft_lstadd_tail(t_list *lst, t_list *new)
{
	t_list	*end;

	end = lst;
	if (!(lst))
		lst = new;
	while (end != NULL)
	{
		if (end->next == NULL)
		{
			end->next = new;
			new->next = NULL;
			break ;
		}
		end = end->next;
	}
}

void	reverse_rotate_a(t_list **lst, t_list **last)
{
	t_list	*temp;
	t_list	*print;
	t_list	*new_end;

	temp = (*lst);
	new_end = (*lst);
	while (new_end -> next != (*last))
		new_end = new_end -> next;
	*lst = *last;
	(*lst) -> next = temp;
	new_end -> next = NULL;
	print = (*lst);
	(*last) = new_end;
	write(1, "rra\n", 4);
}

void	push_b(t_list **headA, t_list **headB)
{
	t_list	*temp2;
	t_list	*temp3;
	
	temp2 = (*headA) -> next;
	(*headA) -> next = NULL;
	if (*headB == NULL)
		*headB = *headA;
	else
	{
		temp3 = *headB;
		*headB = *headA;
		(*headB) -> next = temp3;
	}
	*headA = temp2;
	write(1, "pb\n", 3);
}

void	push_a(t_list **headA, t_list **headB)
{
	t_list	*temp2;
	t_list	*temp3;

	temp2 = (*headB) -> next;
	(*headB) -> next = NULL;
	temp3 = *headA;
	*headA = *headB;
	(*headA) -> next = temp3;
	*headB = temp2;
	write(1, "pa\n", 3);
}

void	reverse_rotate_b(t_list **lst, t_list **last)
{
	t_list	*temp;
	t_list	*print;
	t_list	*new_end;

	temp = (*lst);
	new_end = (*lst);
	while (new_end -> next != (*last))
		new_end = new_end -> next;
	*lst = *last;
	(*lst) -> next = temp;
	new_end -> next = NULL;
	print = (*lst);
	(*last) = new_end;
	write(1, "rrb\n", 4);
}

void	rotate_b(t_list **head, t_list **tail)
{
	t_list	*temp;

	temp = (*head) ->next;
	ft_lstadd_tail(temp,(*head));
	(*tail) = (*head);
	(*head) = temp;
	write(1, "rb\n", 3);
}

void	rotate_a(t_list **head, t_list **tail)
{
	t_list	*temp;

	temp = (*head) ->next;
	ft_lstadd_tail(temp,(*head));
	(*tail) = (*head);
	(*head) = temp;
	write(1, "ra\n", 3);
}
