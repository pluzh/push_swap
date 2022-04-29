/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_rep(int *arr, int size)
{
	int	i;
	int	k;

	i = 0;
	while (i < size)
	{
		k = i + 1;
		while (k < size)
		{
			if (arr[i] == arr[k])
			{
				write(1, "Error\n", 6);
				return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}

static void	ft_is_sort(int *arr, int size)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		if (i + 1 < size && arr[i] > arr[i + 1])
			k++;
		i++;
	}
	if (k == 0)
		exit(1);
}

void	ft_mem_order(int *arr, t_stacks *stack, int size)
{
	int		i;
	t_list	*tmp;

	stack->max = size - 1;
	tmp = stack->stack_a;
	while (tmp)
	{
		i = 0;
		while (i < size)
			if (arr[i++] == tmp->content)
				tmp->order = i;
		tmp = tmp->next;
	}
}

static int	*ft_sort_arr(int *arr, int size, t_stacks *stack)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
			j--;
		}
		i++;
	}
	ft_mem_order(arr, stack, size);
	return (arr);
}

void	ft_start(t_stacks *stack, int k, char **argv)
{
	int	*tmp;

	stack->sort_arr = ft_init_arr(stack->stack_a);
	stack->size_a = (int)ft_lstsize(stack->stack_a);
	if (!ft_is_rep(stack->sort_arr, stack->size_a))
		return ;
	ft_is_sort(stack->sort_arr, stack->size_a);
	tmp = stack->sort_arr;
	stack->sort_arr = ft_sort_arr(tmp, stack->size_a, stack);
	if (stack->size_a < 6)
		ft_small_sort(stack);
	else
		ft_big_sort(stack);
	ft_clean_stack(stack);
	if (k)
		ft_clean_argv(argv);
}
