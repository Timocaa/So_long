/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:39:19 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:40:30 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	elem = lst;
	while (elem != NULL)
	{
		if (elem->next == NULL)
			return (elem);
		else
			elem = elem->next;
	}
	return (NULL);
}
