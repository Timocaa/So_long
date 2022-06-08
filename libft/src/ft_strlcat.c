/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:30:27 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:50:02 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst2;
	const char	*src2;
	size_t		n;
	size_t		dst_len;

	dst2 = dst;
	src2 = src;
	n = size;
	while (n-- && *dst2)
		dst2++;
	dst_len = dst2 - dst;
	n = size - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(src2));
	while (*src2)
	{
		if (n != 1)
		{
			*dst2++ = *src2;
			n--;
		}
		src2++;
	}
	*dst2 = '\0';
	return (dst_len + (src2 - src));
}
