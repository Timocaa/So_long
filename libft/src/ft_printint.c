/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:04:19 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:55:41 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printint(t_printf *tab)
{
	int	d;
	int	neg;
	int	t_len;

	neg = 0;
	d = va_arg(tab->args, int);
	if (d < 0)
	{
		neg = 1;
		d *= -1;
	}
	t_len = ft_calcul_len_int(neg, tab, ft_intlen(d));
	if (!tab->dash)
		ft_putwidht_left_int(tab, t_len);
	ft_putzero_int(d, tab, neg, t_len);
	ft_putnbr_int(d, tab);
	ft_putwidth_right_int(tab, t_len);
}

void	ft_putwidth_right_int(t_printf *tab, int len)
{
	if (!tab->dash)
		return ;
	tab->width -= len;
	while (tab->width-- > 0)
		tab->tot_len += write(1, " ", 1);
}

void	ft_putzero_int(int d, t_printf *tab, int neg, int len)
{
	len -= ft_intlen(d);
	len -= 1;
	if (neg)
		tab->tot_len += write(1, "-", 1);
	else if (tab->sign)
		tab->tot_len += write(1, "+", 1);
	else if (tab->space)
		tab->tot_len += write(1, " ", 1);
	else
		len++;
	while (len-- > 0)
		tab->tot_len += write(1, "0", 1);
}

void	ft_putwidht_left_int(t_printf *tab, int len)
{
	tab->width -= len;
	while (tab->width-- > 0)
		tab->tot_len += write(1, " ", 1);
}

int	ft_calcul_len_int(int neg, t_printf *tab, int len)
{
	int	total;

	if (tab->dot > -1)
	{
		if (len < tab->dot)
			total = tab->dot + neg;
		else
			total = len;
	}
	else if (tab->zero == 1)
	{
		if (len < tab->width)
			total = tab->width;
		else
			total = len;
	}
	else
	{
		total = len;
		if (neg == 1)
			total++;
	}
	return (total);
}
