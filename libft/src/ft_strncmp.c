/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:13:09 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:51:08 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1bis;
	unsigned char	*s2bis;

	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (s1bis[i] && s2bis[i] && s1bis[i] == s2bis[i] && (i < n - 1))
		i++;
	return (s1bis[i] - s2bis[i]);
}
