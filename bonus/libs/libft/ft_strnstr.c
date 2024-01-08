/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:50:50 by davda-si          #+#    #+#             */
/*   Updated: 2023/05/11 12:30:04 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j] != '\0')
	{
		i = 0;
		while (big[j + i] == little[i] && (i + j) < len)
		{
			if (big[j + i] == '\0' && little[i] == '\0')
				return ((char *)&big[j]);
			i++;
		}
		if (little[i] == '\0')
			return ((char *)big + j);
		j++;
	}
	return (NULL);
}
