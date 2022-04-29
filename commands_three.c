/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_to_free;
	t_list	*new;
	int		flag;
	int		order;

	if (*stack_b)
	{
		tmp = *stack_b;
		while ((*stack_b)->next->next)
			*stack_b = (*stack_b)->next;
		order = (*stack_b)->next->order;
		flag = (*stack_b)->next->flag;
		new = ft_lstnew((*stack_b)->next->content, flag, order);
		tmp_to_free = (*stack_b)->next;
		(*stack_b)->next = NULL;
		free(tmp_to_free);
		ft_lstadd_front(&tmp, new);
		*stack_b = new;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = ft_lstlast_del(*stack_a);
	ft_lstadd_front(stack_a, tmp);
	tmp = ft_lstlast_del(*stack_b);
	ft_lstadd_front(stack_b, tmp);
	write(1, "rrr\n", 4);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	int		flag;
	int		order;
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	if (!*stack_b)
	{
		flag = (*stack_a)->flag;
		order = (*stack_a)->order;
		*stack_b = ft_lstnew((*stack_a)->content, flag, order);
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
	else
	{
		tmp = (*stack_a)->next;
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = tmp;
	}
	write(1, "pb\n", 3);
}
