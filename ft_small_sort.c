/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **stack_a)
{
	int		a;
	int		b;
	int		c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b)
	{
		if (b > c)
		{
			rra(stack_a);
			rra(stack_a);
		}
		else
			sa(stack_a);
	}
	if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	ft_sort_two_b(t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (size == 1)
		return ;
	else if ((*stack_b)->content > (*stack_b)->next->content)
		sb(stack_b);
}

void	ft_sort_four(t_stacks *stack, int i)
{
	int		min;
	int		k;
	t_list	*tmp;

	min = stack->sort_arr[i];
	k = 0;
	tmp = stack->stack_a;
	while (stack->stack_a->content != min && ++k)
		stack->stack_a = stack->stack_a->next;
	stack->stack_a = tmp;
	if (k > 0 && k < 3)
		while (k--)
			ra(&stack->stack_a);
	else if (k > 2)
		while (4 - (k++))
			rra(&stack->stack_a);
	pb(&stack->stack_a, &stack->stack_b);
	ft_sort_three(&stack->stack_a);
	pa(&stack->stack_a, &stack->stack_b);
}

void	ft_sort_five_start(t_stacks *stack, int size)
{
	int		min;
	int		k;
	t_list	*tmp;

	if (size == 4)
		ft_sort_four(stack, 0);
	if (size == 5)
	{
		min = stack->sort_arr[0];
		k = 0;
		tmp = stack->stack_a;
		while (stack->stack_a->content != min && ++k)
			stack->stack_a = stack->stack_a->next;
		stack->stack_a = tmp;
		if (k > 0 && k < 3)
			while (k--)
				ra(&stack->stack_a);
		else if (k > 2)
			while (5 - k++)
				rra(&stack->stack_a);
		pb(&stack->stack_a, &stack->stack_b);
		ft_sort_four(stack, 1);
		pa(&stack->stack_a, &stack->stack_b);
	}
}

void	ft_small_sort(t_stacks *stack)
{
	if (stack->size_a == 2)
		sa(&(stack->stack_a));
	else if (stack->size_a == 3)
		ft_sort_three(&(stack->stack_a));
	else if (stack->size_a <= 5)
		ft_sort_five_start(stack, stack->size_a);
}
