/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_put_error(size_t nbr, int sign, int i)
{
	size_t	max;

	max = 2147483648;
	if ((nbr >= max && sign == 1) || (nbr > max && sign == -1) || i > 11)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	nbr;
	size_t	j;

	j = 0;
	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (j++ > 11)
			ft_put_error(nbr, sign, i);
		nbr = nbr * 10 + (str[i++] - '0');
	}
	ft_put_error(nbr, sign, i);
	return (((int)nbr * sign));
}
