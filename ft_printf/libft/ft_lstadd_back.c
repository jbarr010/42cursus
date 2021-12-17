/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:50:36 by jbarredo          #+#    #+#             */
/*   Updated: 2021/09/07 16:19:54 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	end = *lst;
	if (!(*lst))
		*lst = new;
	while (end != NULL)
	{
		if (end->next == NULL)
		{
			end->next = new;
			break ;
		}
		end = end->next;
	}
}
