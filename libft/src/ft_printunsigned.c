/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:00:58 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:56:02 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printunsigned(t_printf *tab)
{
	unsigned int	u;
	int				t_len;

	u = va_arg(tab->args, unsigned int);
	t_len = ft_calcul_len_u(tab, ft_unsignedlen(u));
	if (!tab->dash)
		ft_putwidth_left_u(tab, t_len);
	ft_putzero_unsigned(tab, t_len, u);
	ft_putnbr_u(u, tab);
	ft_putwidth_right_u(tab, t_len);
}

void	ft_putwidth_right_u(t_printf *tab, int len)
{
	if (!tab->dash)
		return ;
	tab->width -= len;
	while (0 < tab->width--)
		tab->tot_len += write(1, " ", 1);
}

void	ft_putzero_unsigned(t_printf *tab, int len, unsigned int u)
{
	len -= ft_unsignedlen(u);
	while (len-- > 0)
		tab->tot_len += write(1, "0", 1);
}

void	ft_putwidth_left_u(t_printf *tab, int len)
{
	tab->width -= len;
	while (0 < tab->width--)
		tab->tot_len += write(1, " ", 1);
}

int	ft_calcul_len_u(t_printf *tab, int u_len)
{
	int	total;

	if (tab->dot > -1)
	{
		if (u_len < tab->dot)
			total = tab->dot;
		else
			total = u_len;
	}
	else if (tab->zero)
	{
		if (u_len < tab->width)
			total = tab->width;
		else
			total = u_len;
	}
	else
		total = u_len;
	return (total);
}
