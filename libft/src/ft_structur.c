/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:09:24 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:56:12 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_printf	*ft_init_tab(t_printf *tab)
{
	tab->width = 0;
	tab->zero = 0;
	tab->dot = -1;
	tab->dash = 0;
	tab->tot_len = 0;
	tab->sign = 0;
	tab->form_hex = 0;
	tab->space = 0;
	return (tab);
}

t_printf	*ft_reset_tab(t_printf *tab)
{
	tab->width = 0;
	tab->zero = 0;
	tab->dot = -1;
	tab->dash = 0;
	tab->sign = 0;
	tab->form_hex = 0;
	tab->space = 0;
	return (tab);
}

void	ft_putnbr_u(unsigned int n, t_printf *tab)
{
	char	c;

	if (n >= 10)
		ft_putnbr_int((n / 10), tab);
	c = n % 10 + 48;
	tab->tot_len += write(1, &c, 1);
}

void	ft_putnbr_int(int n, t_printf *tab)
{
	char	c;

	if (n <= -2147483648)
	{
		tab->tot_len += write(1, "2", 1);
		n = 147483648;
	}
	if (n >= 10)
		ft_putnbr_int((n / 10), tab);
	c = n % 10 + 48;
	tab->tot_len += write(1, &c, 1);
}
