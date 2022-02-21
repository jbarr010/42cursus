/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:14:23 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/08 17:12:01 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_arrtolist(int n, int *arr)
{
	t_list	*head;
	t_list	*temp;
	t_list	*p;
	int		i;

	head = NULL;
	temp = NULL;
	p = NULL;
	i = 0;	
	while (i < n)
	{
		temp = malloc(sizeof(t_list));
		temp->content = arr[i];
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			p = head;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
		}
		i++;	
	}
	return (head);
}

t_list	*ft_arrtoparm(int n, int *arr)
{
	t_list	*head;
	t_list	*temp;
	t_list	*p;
	int		i;

	head = NULL;
	temp = NULL;
	p = NULL;
	i = 0;
	while (i <= n)
	{
		temp = malloc(sizeof(t_list));
		temp->content = arr[i];
		temp->next = NULL;
		if (head == NULL)
			head = temp;
		else
		{
			p = head;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
		}
		i++;
	}
	return (head);
}
