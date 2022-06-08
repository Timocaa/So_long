/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:08:48 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:50:09 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\0' && i < size - 1)
	{
		dst[i] = '\0';
		return (i);
	}
	else
	{
		dst[size - 1] = '\0';
		while (src[i])
			i++;
		return (i);
	}
}
