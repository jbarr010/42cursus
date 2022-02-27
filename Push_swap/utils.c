/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:08:48 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/28 00:03:55 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}

t_list	*list_parm(char **argv)
{
	char	**str;
	int		i;
	int		*a;
	t_list	*head_a;

	str = ft_split(argv[1], 32);
	i = 0;
	while (str[i])
		i++;
	a = fill_parm(i, str);
	if (check_rep(i, a))
	{
		head_a = ft_arrtoparm(i - 1, a);
		free (a);
		free_str(str);
		return (head_a);
	}
	else
	{
		write (1, "Error\n", 6);
		free (a);
		exit(0);
	}
}

t_list	*list_simple(int n, char **argv)
{
	int		*a;
	t_list	*head_a;

	a = fill_stack(n, argv);
	if (check_rep(n, a))
	{
		head_a = ft_arrtolist(n, a);
		free (a);
		return (head_a);
	}
	else
	{
		write(1, "Error\n", 6);
		free (a);
		exit(0);
	}
}

int	ft_strlen(const char *str)
{
	size_t	num;

	num = 0;
	while (str[num] != '\0')
	{
		num++;
	}
	return (num);
}

int	is_sorted(t_list *headA)
{
	t_list	*temp;
	t_list	*move;

	temp = headA;
	move = temp ->next;
	while (move)
	{
		if ((temp -> content) > (move -> content))
			return (1);
		else
		{
			temp = temp -> next;
			move = move -> next;
		}
	}
	return (0);
}
