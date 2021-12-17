/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:18:58 by jbarredo          #+#    #+#             */
/*   Updated: 2021/08/16 13:36:20 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = str;
	while (n > 0)
	{
		temp[i] = (unsigned char) c;
		n--;
		i++;
	}
	return (str);
}
