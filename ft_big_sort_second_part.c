/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_second_part.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_b(t_stacks *stack, int size)
{
	if (size == 2 && stack->stack_b->next->order < stack->stack_b->order)
		sb(&(stack->stack_b));
	else if (size == 3)
	{
		if (stack->stack_b->content > stack->stack_b->next->content)
			sb(&stack->stack_b);
		if (stack->stack_b->next->content > stack->stack_b->next->next->content)
			rrb(&stack->stack_b);
		if (stack->stack_b->content > stack->stack_b->next->content)
			sb(&stack->stack_b);
	}
	while (stack->stack_b)
	{
		pa(&stack->stack_a, &stack->stack_b);
		ra(&stack->stack_a);
		stack->next++;
	}
}

int	ft_serch_max(t_stacks *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack->stack_b;
	max = tmp->order;
	while (tmp)
	{
		if (tmp->order > max)
			max = tmp->order;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_push_stack_b(t_stacks *stack)
{
	if (stack->stack_b->order >= stack->mid_b)
	{
		pa(&stack->stack_a, &stack->stack_b);
		stack->stack_a->flag = stack->flag;
	}
	else if (stack->stack_b->order == stack->next)
	{
		pa(&stack->stack_a, &stack->stack_b);
		ra(&stack->stack_a);
		stack->next++;
	}
	else
		rb(&stack->stack_b);
}

void	ft_sort_stack_b(t_stacks *stack, int i)
{
	int	size;

	size = ft_lstsize(stack->stack_b);
	if (i == 0)
		stack->max_b = stack->mid_b;
	else if (i == 1)
		stack->max_b = stack->max;
	else
		stack->max_b = ft_serch_max(stack);
	stack->mid_b = (stack->max_b - stack->next) / 2 + stack->next;
	if (size <= 3)
	{
		ft_sort_small_b(stack, size);
		return ;
	}
	stack->flag++;
	while (size)
	{
		ft_push_stack_b(stack);
		size--;
	}
	if (i != 0)
		i++;
	if (stack->stack_b)
		ft_sort_stack_b(stack, i);
}
