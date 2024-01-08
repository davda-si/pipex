/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:35:27 by davda-si          #+#    #+#             */
/*   Updated: 2023/05/02 12:32:51 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numchar(int n)
{
	int				i;
	unsigned int	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		i = 2;
		num = -n;
	}
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	num;
	char			*res;

	res = (char *)malloc(numchar(n) + 1);
	if (res == NULL)
	{
		return (NULL);
	}
	i = numchar(n);
	num = n;
	if (n < 0)
	{
		num = -n;
		res[0] = '-';
	}
	res[i] = '\0';
	res[i - 1] = '0';
	while (num > 0)
	{
		i--;
		res[i] = num % 10 + 48;
		num /= 10;
	}
	return (res);
}
