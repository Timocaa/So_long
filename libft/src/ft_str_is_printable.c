/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:46:36 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:49:26 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_str_is_printable(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isprint(s[i]))
			return (0);
		i++;
	}
	return (1);
}
