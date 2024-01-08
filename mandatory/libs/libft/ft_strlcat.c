/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:05:19 by davda-si          #+#    #+#             */
/*   Updated: 2023/05/09 12:24:35 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	if (d >= size)
		return (size + s);
	while (src[i] && (d + i + 1) < size)
	{
		dst[d + i] = src[i];
		i++;
	}
	if (d + i < size)
		dst[d + i] = '\0';
	return (d + s);
}
