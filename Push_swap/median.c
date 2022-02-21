/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:12:13 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/15 19:16:26 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	auxiliar(t_list *headA)
{
	t_list	*aux;
	int		*arr;
	int		n;
	int		i;
	int	m;

	i = 0;
	n = lstsize(headA);
	aux = headA;
	arr = malloc(sizeof(int) * (n + 1));
	if (!arr)
		return (-1);
	while(aux)
	{
		arr[i] = aux -> content;
		aux = aux -> next;
		i++;
	}
	arr[i] = '\0';
	arr = sort_array(arr, n);
	m = quartil(arr, n);
	free(arr);
	return (m);
}

int	*sort_array(int	*arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = i + 1;
	while (j < n)
	{
		if(arr[i] < arr[j])
		{
			i++;
			j++;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i = 0;
			j = i + 1;
		}
	}
	return (arr);
}

int	median(int *stack, int n)
{
	int	i;
	int	m;
	int	*arr;

	arr = stack;
	i = n/2;
	m = arr[i];
	return(m);
}

int	quartil(int *stack, int n)
{
	int	i;
	int	q;
	int	*arr;

	arr = stack;
	i = n/3;
	q = arr[i];
	return(q);
}

int	quartil_second(int *stack, int n)
{
	int	i;
	int	q;
	int	*arr;

	arr = stack;
	i = (n/3) * 2;
	q = arr[i];
	return(q);
}

int	q_value(t_list *headA)
{
	t_list	*aux;
	int		*arr;
	int		n;
	int		i;
	int	m;

	i = 0;
	n = lstsize(headA);
	aux = headA;
	arr = malloc(sizeof(int) * (n + 1));
	if (!arr)
		return (-1);
	while(aux)
	{
		arr[i] = aux -> content;
		aux = aux -> next;
		i++;
	}
	arr[i] = '\0';
	arr = sort_array(arr, n);
	m = quartil_second(arr, n);
	free(arr);
	return (m);
}

