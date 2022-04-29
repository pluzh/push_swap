/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	int	tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->order;
	(*stack_a)->order = (*stack_a)->next->order;
	(*stack_a)->next->order = tmp;
	tmp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = tmp;
	tmp = (*stack_a)->flag;
	(*stack_a)->flag = (*stack_a)->next->flag;
	(*stack_a)->next->flag = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	int	tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->order;
	(*stack_b)->order = (*stack_b)->next->order;
	(*stack_b)->next->order = tmp;
	tmp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp;
	tmp = (*stack_b)->flag;
	(*stack_b)->flag = (*stack_b)->next->flag;
	(*stack_b)->next->flag = tmp;
	write(1, "sb\n", 3);
}

void	ss_sb(t_list **stack_b)
{
	int	tmp;

	tmp = (*stack_b)->order;
	(*stack_b)->order = (*stack_b)->next->order;
	(*stack_b)->next->order = tmp;
	tmp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp;
	tmp = (*stack_b)->flag;
	(*stack_b)->flag = (*stack_b)->next->flag;
	(*stack_b)->next->flag = tmp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	int	tmp;

	if ((*stack_a)->next && (*stack_a)->content)
	{
		tmp = (*stack_a)->order;
		(*stack_a)->order = (*stack_a)->next->order;
		(*stack_a)->next->order = tmp;
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
		tmp = (*stack_a)->flag;
		(*stack_a)->flag = (*stack_a)->next->flag;
		(*stack_a)->next->flag = tmp;
	}
	if ((*stack_b)->next && (*stack_b)->content)
		ss_sb(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		flag;
	int		order;

	if (!(*stack_b))
		return ;
	if (!*stack_a)
	{
		flag = (*stack_b)->flag;
		order = (*stack_b)->order;
		*stack_a = ft_lstnew((*stack_b)->content, flag, order);
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp);
	}
	else
	{
		tmp = (*stack_b)->next;
		ft_lstadd_front(stack_a, *stack_b);
		*stack_b = tmp;
	}
	write(1, "pa\n", 3);
}
