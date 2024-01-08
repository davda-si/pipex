/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:40 by davda-si          #+#    #+#             */
/*   Updated: 2023/09/11 17:47:04 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_hex(unsigned int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		c = c / 16;
		i++;
	}
	return (i);
}

char	*hex_str(unsigned int n, char *b)
{
	char	*str;
	int		i;

	i = count_hex(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = b[n % 16];
		n = n / 16;
		i--;
	}
	return (str);
}

int	ft_hex(unsigned int n, char *b)
{
	char	*str;
	int		i;

	str = hex_str(n, b);
	i = ft_putstr(str);
	free(str);
	return (i);
}

// int	main()
// {
// 	int	i;
//
// 	i = ft_hex(-1, "0123456789abcdef");
// }