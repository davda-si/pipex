/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:05:41 by davda-si          #+#    #+#             */
/*   Updated: 2023/09/11 17:47:11 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*pnt_str(unsigned long n, char *b)
{
	int		size;
	char	*str;

	size = ft_count(n);
	str = (char *)malloc(sizeof(char) * (size + 3));
	if (!str)
		return (0);
	str[size + 2] = '\0';
	str[0] = '0';
	str[1] = 'x';
	while (size > 0)
	{
		str[size + 1] = b[n % 16];
		n = n / 16;
		size--;
	}
	return (str);
}

int	ft_point(void *nmb, char *b)
{
	int				size;
	char			*str;

	if (nmb == 0)
		return (ft_putstr("(nil)"));
	str = pnt_str((unsigned long)nmb, b);
	size = ft_putstr(str);
	free(str);
	return (size);
}
