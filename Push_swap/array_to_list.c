/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:14:23 by jbarredo          #+#    #+#             */
/*   Updated: 2022/01/12 21:58:35 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	arrsize (int *A)
{
	int	i;

	i = 0;
	while (A)
		i++;
	printf("%s", "cuenta");
	return (i);
}*/

t_list	*ft_arrtolist(int n, int *arr)
{
	t_list	*head;
	t_list	*temp;
	t_list	*p;
	int		i;

	head = NULL;
	temp = NULL;
	p = NULL;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	i = 0; 
	while (i <= n)
	{
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
			printf("%d\n", p->content);
		}
		i++;
	}
	return (head);
}

