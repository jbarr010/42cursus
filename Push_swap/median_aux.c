/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:36:44 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/26 19:49:27 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	quartil_second(int *stack, int n)
{
	int	i;
	int	q;
	int	*arr;

	arr = stack;
	i = (n / 3) * 2;
	q = arr[i];
	return (q);
}

int	q_value(t_list *headA)
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
	m = quartil_second(arr, n);
	free(arr);
	return (m);
}

int	m_value(t_list *headA)
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
	m = median(arr, n);
	free(arr);
	return (m);
}
