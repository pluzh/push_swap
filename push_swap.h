/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				order;
	int				flag;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		mid;
	int		mid_b;
	int		max;
	int		max_b;
	int		next;
	int		next_b;
	int		flag;
	int		*sort_arr;
	int		size_a;
}	t_stacks;

char	**ft_split(char const *s, char c, int *argc);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_lstnew(int content, int flag, int order);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_atoi(const char *str);
void	ft_start(t_stacks *stack, int k, char **argv);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ft_small_sort(t_stacks *stack);
t_list	*ft_lstlast_del(t_list *lst);
void	ft_big_sort(t_stacks *stacks);
t_list	*ft_lst_pred_last(t_list *lst);
void	ft_sort_stack_b(t_stacks *stack, int i);
int		*ft_init_arr(t_list *stack_a);
void	ft_clean_stack(t_stacks *stack);
void	ft_clean_argv(char **argv);

#endif
