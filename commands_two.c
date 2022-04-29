/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*new;
	int		flag;
	int		order;

	if (*stack_a)
	{
		order = (*stack_a)->order;
		flag = (*stack_a)->flag;
		new = ft_lstnew((*stack_a)->content, flag, order);
		ft_lstadd_back(stack_a, new);
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*new;
	int		flag;
	int		order;

	if (*stack_b)
	{
		order = (*stack_b)->order;
		flag = (*stack_b)->flag;
		new = ft_lstnew((*stack_b)->content, flag, order);
		ft_lstadd_back(stack_b, new);
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp);
	}
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*free_tmp;

	tmp = ft_lstnew((*stack_a)->content, (*stack_a)->flag, (*stack_a)->order);
	ft_lstadd_back(stack_a, tmp);
	free_tmp = tmp;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(tmp);
	free(free_tmp);
	tmp = ft_lstnew((*stack_b)->content, (*stack_b)->flag, (*stack_b)->order);
	ft_lstadd_back(stack_b, tmp);
	free_tmp = tmp;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(tmp);
	free(free_tmp);
	write(1, "rr\n", 3);
}

t_list	*ft_lstlast_del(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst == NULL)
		return ((void *)0);
	tmp = lst;
	while (tmp->next != NULL)
	{
		if (!tmp->next->next)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	return (tmp);
}

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp_to_free;
	t_list	*new;
	int		flag;
	int		order;

	if (*stack_a)
	{
		tmp = *stack_a;
		while ((*stack_a)->next->next)
			*stack_a = (*stack_a)->next;
		flag = (*stack_a)->next->flag;
		order = (*stack_a)->next->order;
		new = ft_lstnew((*stack_a)->next->content, flag, order);
		tmp_to_free = (*stack_a)->next;
		(*stack_a)->next = NULL;
		if (tmp_to_free)
			free(tmp_to_free);
		ft_lstadd_front(&tmp, new);
		*stack_a = new;
		write(1, "rra\n", 4);
	}
}
