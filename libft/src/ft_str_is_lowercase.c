/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:35:37 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:49:12 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_str_is_lowercase(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_islower(s[i]))
			return (0);
		i++;
	}
	return (1);
}
