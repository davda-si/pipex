/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:37:22 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/05 15:51:58 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0' && n > 1))
	{
		i++;
		j++;
		n--;
		if (n == 0)
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
