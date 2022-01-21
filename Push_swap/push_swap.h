/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:54:32 by jbarredo          #+#    #+#             */
/*   Updated: 2022/01/12 20:31:40 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int	*fill_stack(int n, char **parm);
void	print_stack(int *stack);
int	check_char(int n, char **str);
int	check_rep(int n, int *stack);
char	**ft_split(char const *s, char c);
void	print_parm(int *stack);
int	*fill_parm(int i, char **str);
int	check_limits(int n, int *stack);
int	ft_atoi_error(char *str);
t_list	*ft_arrtolist(int n, int *data);
//int	arrsize(int *A);
