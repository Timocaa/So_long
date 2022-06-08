/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:41:47 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:43:19 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = s;
	while (n--)
		str[i++] = c;
	return (s);
}
