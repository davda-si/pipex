/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:56:11 by davda-si          #+#    #+#             */
/*   Updated: 2023/05/12 12:38:26 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*i;
	t_list	*j;
	t_list	*k;

	if (lst)
	{
		i = lst;
		k = ft_lstnew(f(i->content));
		if (!k)
			return (NULL);
		i = i->next;
		while (i)
		{
			j = ft_lstnew(f(i->content));
			if (!j)
			{
				ft_lstclear(&k, del);
				return (NULL);
			}
			ft_lstadd_back(&k, j);
			i = i->next;
		}
		return (k);
	}
	return (NULL);
}
