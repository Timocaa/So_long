/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:31 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:43:10 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	if (dest == NULL || src == NULL)
		return (NULL);
	src2 = (char *)src;
	dest2 = (char *)dest;
	while (n--)
	{
		if (src < dest)
			dest2[n] = src2[n];
		else
			*dest2++ = *src2++;
	}
	return (dest);
}
