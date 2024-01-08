/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:21:26 by davda-si          #+#    #+#             */
/*   Updated: 2023/05/11 12:30:59 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	f;
	size_t	size;
	char	*result;

	if (s1 == 0 || set == 0)
		return (NULL);
	s = 0;
	f = ft_strlen(s1) - 1;
	while (ft_set(s1[s], set) && s1[s])
		s++;
	while (ft_set(s1[f], set) && f > s)
		f--;
	size = f - s + 1;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + s, size + 1);
	return (result);
}
