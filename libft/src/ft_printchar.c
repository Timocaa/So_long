/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:16:08 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:55:06 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printchar(t_printf *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if ((tab->zero || tab->width) && !tab->dash)
		ft_putwidth_left_char(tab);
	tab->tot_len += write(1, &c, 1);
	if (tab->width && tab->dash)
		ft_putwidth_right_char(tab);
}

void	ft_putwidth_left_char(t_printf *tab)
{
	int	i;

	i = 0;
	tab->width -= 1;
	while (i < tab->width)
	{
		if (tab->zero == 1)
			tab->tot_len += write (1, "0", 1);
		else
			tab->tot_len += write (1, " ", 1);
		i++;
	}
}

void	ft_putwidth_right_char(t_printf *tab)
{
	int	i;

	i = 0;
	tab->width -= 1;
	while (i < tab->width)
	{
		tab->tot_len += write (1, " ", 1);
		i++;
	}
}
