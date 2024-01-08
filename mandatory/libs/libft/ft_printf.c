/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:36:52 by davda-si          #+#    #+#             */
/*   Updated: 2023/09/11 17:46:38 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				j += ft_putchar('%');
			i++;
			j += ft_args(str[i], ap);
		}
		else
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (j);
}

// int	main(void)
// {
// 	int	i;
// 	int	j;
//
// 	i = printf("ola o meu %d e joao\n", 1);
// 	j = ft_printf("%d\n", 1);
// 	printf("%d\n", i);
// 	printf("%d\n", j);
// }