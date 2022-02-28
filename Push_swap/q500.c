/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q500.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:59:16 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/28 13:10:18 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	quartil_1(int *stack, int n)
{
	int	i;
	int	q;
	int	*arr;

	arr = stack;
	i = n / 5;
	q = arr[i];
	return (q);
}

int	q_value_1(t_list *headA)
{
	t_list	*aux;
	int		*arr;
	int		n;
	int		i;
	int		m;

	i = 0;
	n = lstsize(headA);
	aux = headA;
	arr = malloc(sizeof(int) * (n + 1));
	if (!arr)
		return (-1);
	while (aux)
	{
		arr[i] = aux -> content;
		aux = aux -> next;
		i++;
	}
	arr[i] = '\0';
	arr = sort_array(arr, n);
	m = quartil_1(arr, n);
	free(arr);
	return (m);
}

int	quartil_2(int *stack, int n)
{
	int	i;
	int	q;
	int	*arr;

	arr = stack;
	i = (n / 5) * 2;
	q = arr[i];
	return (q);
}

int	q_value_2(t_list *headA)
{
	t_list	*aux;
	int		*arr;
	int		n;
	int		i;
	int		m;

	i = 0;
	n = lstsize(headA);
	aux = headA;
	arr = malloc(sizeof(int) * (n + 1));
	if (!arr)
		return (-1);
	while (aux)
	{
		arr[i] = aux -> content;
		aux = aux -> next;
		i++;
	}
	arr[i] = '\0';
	arr = sort_array(arr, n);
	m = quartil_2(arr, n);
	free(arr);
	return (m);
}
