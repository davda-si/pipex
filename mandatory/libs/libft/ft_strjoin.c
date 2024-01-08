/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:17:15 by davda-si          #+#    #+#             */
/*   Updated: 2024/01/03 16:21:39 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	i = -1;
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i] != '\0')
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*
int main()
{
	char	*s1 = "Hello";
	char	*s2 = "Guys";
	char	*s3 = ft_strjoin(s1, s2);
	printf("%s", s3);
}*/