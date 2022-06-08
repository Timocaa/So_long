/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:38:47 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:55:31 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_print_hexa(t_printf *tab, const char c)
{
	unsigned int	x;
	int				t_len;
	int				form;

	form = 0;
	if (c == 'X')
		form = 1;
	x = va_arg(tab->args, unsigned int);
	t_len = ft_calcul_len_hex(ft_hexalen(x), tab);
	ft_putwidth_left_hexa(tab, t_len, x, form);
	if (form == 1)
		ft_putnbr_base(x, "0123456789ABCDEF", tab);
	else
		ft_putnbr_base(x, "0123456789abcdef", tab);
	ft_putwidth_right_hexa(tab, t_len);
}

void	ft_putwidth_right_hexa(t_printf *tab, int len)
{
	if (!tab->dash)
		return ;
	tab->width -= len;
	while (0 < tab->width--)
		tab->tot_len += write(1, " ", 1);
}

void	ft_putwidth_left_hexa(t_printf *tab, int len, unsigned int x, int form)
{
	if (!tab->dash)
	{
		tab->width -= len;
		while (0 < tab->width)
			tab->tot_len += write(1, " ", 1);
	}
	if (tab->form_hex && x)
	{
		if (form == 1)
			tab->tot_len += write(1, "0X", 2);
		else
			tab->tot_len += write(1, "0x", 2);
	}
	len -= ft_hexalen(x);
	if (tab->form_hex)
		len -= 2;
	while (len-- > 0)
		tab->tot_len += write(1, "0", 1);
}

int	ft_calcul_len_hex(int h_len, t_printf *tab)
{
	int	total;

	if (tab->dot > -1)
	{
		if (h_len < tab->dot)
			total = tab->dot;
		else
			total = h_len;
	}
	else if (tab->zero)
	{
		if (h_len < tab->width)
			total = tab->width;
		else
			total = h_len;
	}
	else
		total = h_len;
	if (tab->form_hex)
		total += 2;
	return (total);
}
