/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:43:56 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/15 19:54:35 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		n;
	int		size;
	int		*A;
	char	**str;
	int		i;
	//int		j;
	//int		*arr;
	//int		mediana;
	//int	quartil;
	//int	quartil2;
	int	q1;
	int	q2;
	int	q3;
	int	q4;
	t_list	*headA;
	t_list	*headB;
	t_list	*tailA;
	t_list	*tailB;
	//t_list	*printA;
	//t_list	*printB;

	headA = NULL;
	headB = NULL;
	tailB = NULL;
	if (argc <= 1)
	{
		//printf("%s", "donde estan los tios???");
		return(0);
	}
	n = argc - 1;	
	if(check_char(n, argv))
	{
		if (argc == 2)
		{
			str = ft_split(argv[1], 32);
			i = 0;
			while(str[i])
				i++;
			//printf("la I es: %d\n", i);
			A = fill_parm(i, str);
			if (check_rep(i, A))
			{
				print_parm(A);
				//printf("%s\n", "todo bien arg");
				ft_arrtoparm(i - 1, A);
			}
			else
			{
				//printf("%s\n", "se repite");
				return (0);
			}
		}
		if (argc > 2)
		{
			A = fill_stack(n, argv);
			if(check_rep(n, A))
			{
				//print_stack(A);
				//printf("%s", "todo bien simple\n");
				headA = ft_arrtolist(n, A);	
				tailA = ft_lstlast(headA);
				//printf("-----: %d\n", headA -> content);
				//swap(headA);
			//	rotate (head);
				//reverse_rotateA(&headA, &tailA);
				//pushB(&headA, &headB);
				//pushB(&headA, &headB);
				//sort_three(&headA, &tailA);
				//quartil = auxiliar(headA);
				//quartil2 = q_value(headA);
				size = lstsize(headA);
				//printf("MEDIANA : %d\n", mediana);
				//sort_five(&headA, &headB, &tailA, mediana);
				//push_big(&headA, &headB, &tailA, &tailB, quartil2, n);
				//push_medium(&headA, &headB, &tailA, &tailB,quartil, quartil2, n);
				q1 = q_value_1(headA);
				q2 = q_value_2(headA);
				q3 = q_value_3(headA);
				q4 = q_value_4(headA);
				push_5(&headA, &headB, &tailA, &tailB,     q3, q4, n);
				push_3(&headA, &headB, &tailA, &tailB,         q2, q3, n);
				push_2(&headA, &headB, &tailA, &tailB,         q1, q2, n);
				/*printA = headA;
				while (printA)
				{
					printf("ContentA %d\n", printA -> content);
					printA = printA ->next;
				}*/
			}	
			else
				printf("%s", "\033[0;31mERROR REP\n\033[0m");
		}
	}
	else
		printf("%s", "\033[0;31mERROR CHAR\n\033[0m");
	return (0);
}
