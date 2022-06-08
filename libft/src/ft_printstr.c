/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:05:34 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:55:51 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printstr(t_printf *tab)
{
	char	*str;
	size_t	len;

	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		tab->tot_len += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	if (tab->dot >= 0)
		len = ft_dotlen(tab, len);
	if ((tab->zero || tab->width) && !tab->dash)
		ft_putwidth_left_str(tab, len);
	tab->tot_len += write(1, str, len);
	if (tab->width && tab->dash)
		ft_putwidth_right_str(tab, len);
}

size_t	ft_dotlen(t_printf *tab, size_t len)
{
	if (len > (size_t)tab->dot)
		len = tab->dot;
	return (len);
}

void	ft_putwidth_left_str(t_printf *tab, size_t len)
{
	tab->width -= len;
	while (0 < tab->width--)
	{
		if (tab->zero)
			tab->tot_len += write(1, "0", 1);
		else
			tab->tot_len += write(1, " ", 1);
	}
}

void	ft_putwidth_right_str(t_printf *tab, size_t len)
{
	tab->width -= len;
	while (0 < tab->width--)
		tab->tot_len += write(1, " ", 1);
}
