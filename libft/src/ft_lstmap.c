/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:27:16 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:40:43 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*first_elem;
	void	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	tmp = (*f)(lst->content);
	first_elem = ft_lstnew(tmp);
	if (first_elem == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst->content);
		nlst = ft_lstnew(tmp);
		if (nlst == NULL)
		{
			ft_lstdelone(first_elem, (*del));
			return (NULL);
		}
		ft_lstadd_back(&first_elem, nlst);
		lst = lst->next;
	}
	nlst = NULL;
	return (first_elem);
}
