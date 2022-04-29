/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:09 by lmichel           #+#    #+#             */
/*   Updated: 2021/11/26 12:30:12 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_freearr(char **ret)
{
	unsigned int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
	return (NULL);
}

static size_t	ft_hmstr(char const *str, char c)
{
	size_t			i;
	size_t			ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] && str[i + 1] == c)
			|| (str[i] != c && !str[i + 1]))
			ret++;
		i++;
	}
	return (ret);
}

static size_t	ft_hmchr(const char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c, int *argc)
{
	size_t	j;
	char	**ret;

	*argc = 0;
	j = 0;
	if (!s)
		return (NULL);
	ret = malloc((ft_hmstr(s, c) + 2) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (s[(*argc)++] == c)
		j++;
	*argc = 1;
	ret[0] = ft_strdup("push_swap\0");
	while (*argc < (int)ft_hmstr(s, c) + 1)
	{
		ret[*argc] = ft_substr(s, j, ft_hmchr(&s[j], c));
		if (!(ret[(*argc)++]))
			return (ft_freearr(ret));
		j += ft_hmchr(&s[j], c);
		while (s[j] == c)
			j++;
	}
	ret[*argc] = NULL;
	return (ret);
}
