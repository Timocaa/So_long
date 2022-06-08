/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:43:28 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:54:38 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_width(t_printf *tab, const char *format, int i)
{
	int	nbr;

	nbr = ft_atoi(&format[i]);
	tab->width = nbr;
	while (ft_isdigit(format[i]) != 0)
		i++;
	return (i);
}

int	ft_dot(t_printf *tab, const char *format, int i)
{
	int	nbr;

	nbr = ft_atoi(&format[i]);
	tab->dot = nbr;
	while (ft_isdigit(format[i]) != 0)
		i++;
	return (i);
}

int	ft_hexalen(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

void	ft_putnbr_base(unsigned long nb, char *base, t_printf *tab)
{
	unsigned long	z;
	char			c;

	z = nb;
	if (z >= 16)
		ft_putnbr_base((z / 16), base, tab);
	c = base[nb % 16];
	tab->tot_len += write(1, &c, 1);
}

int	ft_unsignedlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}
