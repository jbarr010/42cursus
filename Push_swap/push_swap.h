/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:54:32 by jbarredo          #+#    #+#             */
/*   Updated: 2022/02/26 22:38:12 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		*fill_stack(int n, char **parm);
void	print_stack(int *stack);
int		check_char(int n, char **str);
int		check_rep(int n, int *stack);
char	**ft_split(char const *s, char c);
void	print_parm(int *stack);
int		*fill_parm(int i, char **str);
int		check_limits(int n, int *stack);
int		ft_atoi_error(char *str);
t_list	*ft_arrtolist(int n, int *data);
t_list	*ft_arrtoparm(int n, int *data);
t_list	*swap(t_list *head);
t_list	*ft_lstlast(t_list *head);
void	rotate_a(t_list **head, t_list **tail);
void	ft_lstadd_tail(t_list *lst, t_list *new);
void	ft_lstadd_head(t_list *lst, t_list *new);
void	reverse_rotate_a(t_list **lst, t_list **last);
void	push_b(t_list **headA, t_list **headB);
void	reverse_rotate_b(t_list **lst, t_list **last);
void	rotate_b(t_list **head, t_list **tail);
void	sort_three(t_list **head, t_list **tail);
void	push_a(t_list **headA, t_list **headB);
void	prepare_five(t_list **headA, t_list **headB, t_list **tailA, int m);
int		lstsize(t_list *lst);
int		auxiliar(t_list *headA);
int		*sort_array(int	*arr, int n);
int		median(int *stack, int n);
void	sort_five(t_list **headA, t_list **tailA);
t_list	*swap_b(t_list *head);
int		smart_rotate(t_list *head, t_list *num);
int		numbers_to_push(int n);
void	sort_b(t_list **headA, t_list **headB, t_list **tailB);
void	push_big(t_list **headA, t_list **tailA,
			t_list **headB, t_list **tailB);
void	push_sm(t_list **headA, t_list **headB,
			t_list **tailA, t_list **tailB);
int		quartil(int *stack, int n);
void	push_med(t_list **headA, t_list **headB,
			t_list **tsilB, t_list **tailA);
int		quartil_second(int *stack, int n);
int		q_value(t_list *headA);
int		quartil_1(int *stack, int n);
int		q_value_1(t_list *headA);
int		quartil_2(int *stack, int n);
int		q_value_2(t_list *headA);
int		quartil_3(int *stack, int n);
int		q_value_3(t_list *headA);
int		quartil_4(int *stack, int n);
int		q_value_4(t_list *headA);
int		numbers_to_push_500(int n);
void	push_5(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB);
void	push_4(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB);
void	push_3(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB);
void	push_2(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB);
void	push_1(t_list **headA, t_list **headB, t_list **tailA, t_list **tailB);
int		numbers_to_push_500(int n);
t_list	*list_parm (char ** argv);
t_list	*list_simple(int n, char **argv);
void	sort_small(int	size, t_list **headA, t_list **tailA);
void	sort_two(t_list **head);
void	sort_four(t_list **headA, t_list **tailA);
void	sort_hundred(t_list **headA, t_list **tailA);
void	sort_500(t_list **headA, t_list **tailA);
void    sort_rest(t_list **headA, t_list **tailA, int n);
int		numbers_to_push_rest(int n);
void	push_rest_2(t_list **headA, t_list **headB, t_list **tailA, t_list     **tailB, int m, int n);
void	push_rest(t_list **headA, t_list **headB, t_list **tailA, t_list **    tailB, int m, int n);
int		m_value(t_list *headA);
void	size_choose(t_list *head_a, t_list *tail_a, int n, int size);
int		ft_strlen(const char *str);
t_list	*create_temp(int i);
t_list	*find_max(t_list **headB);
t_list  *ask_push(t_list **headA, t_list **headB, t_list *temp, t_list **tailA);
#endif

