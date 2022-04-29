/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_pred_last(t_list *lst)
{
	t_list	*tmp;
	t_list	*ret;

	if (lst == NULL)
		return ((void *)0);
	tmp = lst;
	while (tmp->next != NULL)
	{
		ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

void	ft_push_b(t_stacks *stack)
{
	int	flag;

	flag = stack->stack_a->flag;
	while (stack->stack_a->flag == flag && stack->stack_a->order != 1)
	{
		if (stack->stack_a->order == stack->next)
		{
			ra(&stack->stack_a);
			stack->next++;
		}
		else
			pb(&stack->stack_a, &stack->stack_b);
	}
}

void	ft_sort_third_part(t_stacks *stack)
{
	t_list	*tmp;

	stack->mid_b = (stack->max - stack->next) / 2 + stack->next;
	while (stack->stack_a->order > stack->mid)
	{
		if (stack->stack_a->order <= stack->mid_b)
			pb(&stack->stack_a, &stack->stack_b);
		else
			ra(&stack->stack_a);
	}
	tmp = ft_lstlast(stack->stack_a);
	while (tmp->order > stack->mid)
	{
		if (stack->stack_b->order != stack->next)
			rrr(&stack->stack_a, &stack->stack_b);
		else
			rra(&stack->stack_a);
		tmp = ft_lstlast(stack->stack_a);
	}
	ft_sort_stack_b(stack, 1);
	while (stack->stack_a->order != 1)
	{
		ft_push_b(stack);
		ft_sort_stack_b(stack, 1);
	}
}

void	ft_sort_second_part(t_stacks *stack)
{
	int	flag;

	flag = stack->stack_a->flag;
	if (flag == 0)
	{
		ft_sort_third_part(stack);
		return ;
	}
	while (stack->stack_a->flag == flag)
	{
		if (stack->stack_a->order == stack->next)
		{
			ra(&stack->stack_a);
			stack->next++;
		}
		else
			pb(&stack->stack_a, &stack->stack_b);
	}
	if (stack->stack_b)
		ft_sort_stack_b(stack, 2);
	if (stack->stack_a->flag != 0)
		ft_sort_second_part(stack);
}

void	ft_big_sort(t_stacks *stack)
{
	int	size;

	size = stack->size_a;
	stack->mid = stack->max / 2 + stack->next;
	while (size)
	{
		if (stack->stack_a->order <= stack->mid)
			pb(&stack->stack_a, &stack->stack_b);
		else if (size != 1)
			ra(&stack->stack_a);
		size--;
	}
	stack->mid_b = stack->mid;
	ft_sort_stack_b(stack, 0);
	ft_sort_second_part(stack);
	if (stack->stack_a->order != 1)
		ft_sort_third_part(stack);
}
