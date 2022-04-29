/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean_stack(t_stacks *stack)
{
	t_list	*tmp;

	while (stack->stack_a)
	{
		tmp = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		free(tmp);
	}
	free(stack->sort_arr);
}

void	ft_clean_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	ft_check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9')
			&& !(argv[i][j] == '-' || argv[i][j] == '+'))
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stack;
	int			i;
	int			k;
	t_list		*tmp;

	if (argc < 2)
		exit (1);
	k = 0;
	if (argc == 2 && ++k)
		argv = ft_split(argv[1], ' ', &argc);
	ft_check_argv(argc, argv);
	stack.stack_a = NULL;
	stack.stack_b = NULL;
	stack.next = 1;
	stack.flag = 0;
	i = 1;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]), 0, 0);
		ft_lstadd_back(&stack.stack_a, tmp);
		i++;
	}
	ft_start(&stack, k, argv);
	return (0);
}
