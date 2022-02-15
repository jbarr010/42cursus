/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:54:32 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/15 19:54:31 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}	t_list;

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
t_list	*ft_arrtoparm(int n, int *data);
t_list	*swap(t_list *head);
t_list	*ft_lstlast(t_list *head);
void	rotateA(t_list **head, t_list **tail);
void	ft_lstadd_tail(t_list *lst, t_list *new);
void	ft_lstadd_head(t_list *lst, t_list *new);
void	reverse_rotateA(t_list **lst, t_list **last);
void	pushB(t_list **headA, t_list **headB);
void	reverse_rotateB(t_list **lst, t_list **last);
void	rotateB(t_list **head, t_list **tail);
void	sort_three(t_list **head, t_list **tail);
void	pushA(t_list **headA, t_list **headB);
void	prepare_five(t_list **headA, t_list **headB, t_list **tailA, int m);
int		lstsize(t_list *lst);
int		auxiliar(t_list *headA);
int		*sort_array(int	*arr, int n);
int		median(int *stack, int n);
void	sort_five(t_list **headA, t_list **headB, t_list **tailA, int m);
t_list	*swapB(t_list *head);
int	smart_rotate(t_list *head, t_list *num);
int	numbers_to_push(int	n);
void	sort_B(t_list **headA, t_list **headB, t_list **tailB);
void	push_big(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int m, int n);
//int	arrsize(int *A);
void    push_small(t_list **headA, t_list **headB, t_list **tailA, t_list *    *tailB, int m, int n);
int quartil(int *stack, int n);
void    push_medium(t_list **headA, t_list **headB, t_list     **tailA, t_list **tailB, int q, int q2, int n);
int quartil_second(int *stack, int n);
 int q_value(t_list *headA);
 int quartil_1(int *stack, int n);
 int q_value_1(t_list *headA);
 int quartil_2(int *stack, int n);
 int q_value_2(t_list *headA);
 int quartil_3(int *stack, int n);
 int q_value_3(t_list *headA);
 int quartil_4(int *stack, int n);
 int q_value_4(t_list *headA);
 int numbers_to_push_500(int n);
 void    push_5(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q3, int q4, int n);
 void    push_4(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q3, int q4, int n);
 void    push_3(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q2, int q3, int n);
 void    push_2(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q1, int q2, int n);
 void    push_1(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB, int q1, int n);
 int numbers_to_push_500(int n);
#endif
