/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_init_arr(t_list *stack_a)
{
	int		*arr;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a;
	arr = (int *)malloc(sizeof(int) * ft_lstsize(stack_a));
	while (i < ft_lstsize(stack_a))
	{
		arr[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	return (arr);
}
