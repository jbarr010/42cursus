/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:21:32 by jbarredo          #+#    #+#             */
/*   Updated: 2021/07/22 19:25:56 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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
