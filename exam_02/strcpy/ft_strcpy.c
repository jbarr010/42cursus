/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:43:43 by jbarredo          #+#    #+#             */
/*   Updated: 2022/05/04 19:18:03 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//s1 = malloc(sizeof(char *));
	while(s2[i])
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
	s1[j] = s2[i];
	return(s1);
}

int	main()
{
	char	s2[] = "Hola que tal?";
	char	s1[] = "Hola";

	//s2 = "Hola que tal?";
	//s1 = NULL;
	printf("S1 inicial: %s\n", s1);
	printf("S2 inicial: %s\n", s2);
	ft_strcpy(s1, s2);
	printf("S1 final: %s\n", s1);
	return (0);
}
