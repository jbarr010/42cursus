/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:14:23 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/28 13:09:08 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
		temp = create_temp(arr[i]);
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
		temp = create_temp(arr[i]);
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

t_list	*create_temp(int i)
{
	t_list	*temp;

	temp = NULL;
	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->content = i;
	temp->next = NULL;
	return (temp);
}
