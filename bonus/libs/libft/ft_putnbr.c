/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:30:44 by davda-si          #+#    #+#             */
/*   Updated: 2023/09/11 17:47:23 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numb(long int c)
{
	long int	i;

	i = 1;
	if (c < 0)
	{
		i++;
		c = -c;
	}
	if (c <= 9)
		return (i);
	while ((c / 10) > 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(long int c)
{
	int	minus;

	minus = 0;
	if (c < 0)
	{
		ft_putchar('-');
		minus = 1;
		c = -c;
	}
	if (c >= 10)
		ft_putnbr(c / 10);
	ft_putchar(c % 10 + '0');
	return (count_numb(c) + minus);
}
