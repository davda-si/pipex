/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:12:49 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/12 16:23:36 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freethem(char **ss)
{
	int	i;

	i = 0;
	while (ss[i] != 0)
	{
		free(ss[i]);
		i++;
	}
	free(ss);
	return (NULL);
}

static int	words(char const *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wc++;
		i++;
	}
	return (wc);
}

static int	letters(char const *s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] != c && s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			break ;
		i++;
		l++;
	}
	return (l + 1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		st;
	char	**res;

	res = malloc(sizeof(char *) * (words(s, c) + 1));
	if (!res)
		return (NULL);
	st = 0;
	i = 0;
	while (s[st] != '\0')
	{
		if (s[st] != c)
		{
			res[i] = ft_substr(s, st, letters(s, c, st));
			if (!res[i++])
				return (freethem(res));
			st += letters(s, c, st);
		}
		else
			st++;
	}
	res[i] = NULL;
	return (res);
}
