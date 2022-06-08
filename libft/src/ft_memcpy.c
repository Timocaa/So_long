/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:03:00 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:42:36 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	if (!dest && !src)
		return (dest);
	dest2 = dest;
	src2 = (char *)src;
	while (n--)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
	}
	return (dest);
}
