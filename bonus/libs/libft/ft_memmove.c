/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:43:57 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/05 16:31:04 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*d;
	const unsigned char		*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = -1;
	d = dest;
	s = src;
	if (dest <= src || dest >= (src + n))
		while (++i < n)
			d[i] = s[i];
	else
	{
		i += n;
		while ((int)i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}
