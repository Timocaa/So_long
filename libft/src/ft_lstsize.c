/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:19:56 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:41:35 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*elem;
	int		count;

	count = 0;
	if (lst == NULL)
		return (count);
	elem = lst;
	while (elem != NULL)
	{
		count++;
		elem = elem->next;
	}
	return (count);
}
