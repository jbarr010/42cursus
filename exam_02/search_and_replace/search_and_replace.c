/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:50:45 by jbarredo          #+#    #+#             */
/*   Updated: 2022/05/04 20:06:30 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	char	c1;
	char	c2;
	int		i;
	int		j;

	if(argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	while(argv[2][i])
		i++;
	if(i != 1)
		return(0);
	while(argv[3][j])
		j++;
	if(j != 1)
		return(0);
	str = argv[1];
	c1 = argv[2][0];
	c2 = argv[3][0];
	i = 0;
	j = 0;
	while(str[i])
	{
		if(str[i] == c1)
		{
			str[i] = c2;
			i++;
		}
		else
			i++;
	}
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	write(1, "\n", 1);
}
