/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:53:02 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:42:20 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	i = 0;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (str1[i] != str2[i])
		{
			if ((str1[i] - str2[i]) > 0)
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
