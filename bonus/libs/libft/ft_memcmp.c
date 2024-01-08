/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:25:35 by davda-si          #+#    #+#             */
/*   Updated: 2023/05/09 11:42:05 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;
	size_t				i;

	i = 0;
	t1 = s1;
	t2 = s2;
	if (n == 0)
		return (0);
	while (i < n && t1[i] == t2[i])
		i++;
	if (i == n)
		return (0);
	return (t1[i] - t2[i]);
}
