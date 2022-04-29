/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i + 1);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return ((void *)0);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_list	*ft_lstnew(int content, int flag, int order)
{
	t_list	*begin;

	begin = malloc(sizeof(t_list));
	if (begin == NULL)
		return ((void *)0);
	begin->content = content;
	begin->order = order;
	begin->flag = flag;
	begin->next = NULL;
	return (begin);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = new;
	if (!*lst)
		*lst = tmp;
	else
	{
		new->next = *lst;
		*lst = tmp;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
		ft_lstadd_front(lst, new);
	else if (*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}
