/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:00:48 by davda-si          #+#    #+#             */
/*   Updated: 2023/09/11 17:46:58 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_args(char str, va_list ap)
{
	if (str == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (str == 'p')
		return (ft_point(va_arg(ap, void *), "0123456789abcdef"));
	if (str == 'i' || str == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (str == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)));
	if (str == 'x')
		return (ft_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (str == 'X')
		return (ft_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else
		return (0);
}
