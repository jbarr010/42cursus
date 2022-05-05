/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:23:44 by jbarredo          #+#    #+#             */
/*   Updated: 2022/05/04 19:49:45 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	*str;

	if(argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	str = argv[1];
	while(str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			j = str[i] - 96;
			//printf("j: %d\n", j);
			while(j)
			{
				write(1, &str[i], 1);
				j--;
			}
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			j = str[i] - 64;
			while(j)
			{
				write(1, &str[i], 1);
				j--;
			}
		}
		else
			write(1, &&&str[i], 1);
		i++;
	}
		write(1, "\n", 1);
}
