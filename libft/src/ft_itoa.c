/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:07:30 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:39:20 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	len = ft_intlen(n);
	nbr = n;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		str[0] = '0';
	str[len] = '\0';
	len--;
	while (nbr)
	{
		str[len] = nbr % 10 + 48;
		nbr /= 10;
		len--;
	}
	return (str);
}
