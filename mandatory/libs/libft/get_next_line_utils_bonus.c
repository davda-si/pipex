/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:58:04 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/15 17:29:11 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_gnl2(const char *s)
{
	size_t	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] && s[a] != '\n')
		a++;
	if (s[a] == '\n')
		a++;
	return (a);
}

char	*ft_strjoin_gnl2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	str[i + j] = '\0';
	return (str);
}

int	time_to_free(char *buff)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (buff[i])
	{
		if (check)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			check = 1;
		buff[i++] = '\0';
	}
	return (check);
}
