/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:27:06 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:54:49 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printaddr(t_printf *tab)
{
	unsigned long	p;
	int				t_len;

	p = (unsigned long)va_arg(tab->args, void *);
	if (p == 0)
	{
		tab->tot_len += write(1, "(nil)", 5);
		return ;
	}
	t_len = ft_calcul_len_addr(tab, ft_hexalen(p));
	ft_putwidth_left_addr(tab, t_len);
	tab->tot_len += write(1, "0x", 2);
	ft_putzero_addr(tab, t_len, p);
	ft_putnbr_base(p, "0123456789abcdef", tab);
	ft_putwidth_right_addr(tab, t_len);
}

void	ft_putwidth_right_addr(t_printf *tab, int len)
{
	if (!tab->dash)
		return ;
	tab->width -= (len + 2);
	while (0 < tab->width--)
		tab->tot_len += write(1, " ", 1);
}

void	ft_putzero_addr(t_printf *tab, int len, unsigned long p)
{
	len -= ft_hexalen(p);
	while (0 < len--)
		tab->tot_len += write(1, "0", 1);
}

void	ft_putwidth_left_addr(t_printf *tab, int len)
{
	if (tab->dash)
		return ;
	tab->width -= (len + 2);
	while (0 < tab->width--)
		tab->tot_len += write(1, " ", 1);
}

int	ft_calcul_len_addr(t_printf *tab, int hexalen)
{
	int	total;

	if (tab->dot)
	{
		if (hexalen < tab->dot)
			total = tab->dot - 1;
		else
			total = hexalen;
	}
	else if (tab->zero)
	{
		if (hexalen < tab->width)
			total = tab->width - 2;
		else
			total = hexalen - 2;
	}
	else
		total = hexalen;
	return (total);
}
