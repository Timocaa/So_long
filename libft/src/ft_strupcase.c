/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:36:59 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:52:16 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strupcase(const char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	tmp = (char *)str;
	while (tmp[i])
	{
		tmp[i] = ft_toupper(tmp[i]);
		i++;
	}
	return (tmp);
}
