/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_and_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:26:15 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:54:27 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_get_argument(t_printf *tab, const char *format, int i)
{
	if (format[i] == 'c')
		ft_printchar(tab);
	else if (format[i] == 's')
		ft_printstr(tab);
	else if (format[i] == 'p')
		ft_printaddr(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_printint(tab);
	else if (format[i] == 'u')
		ft_printunsigned(tab);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_print_hexa(tab, format[i]);
	else if (format[i] == '%')
		tab->tot_len += write(1, "%", 1);
	return (i);
}

int	ft_check_flags(t_printf *tab, const char *format, int i)
{
	while (ft_isalpha(format[i]) == 0 && format[i] != '%')
	{
		if (format[i] == '-' && ++i)
			tab->dash = 1;
		if (format[i] == '0' && ++i)
			tab->zero = 1;
		if (ft_isdigit(format[i]))
			i = ft_width(tab, format, i);
		if (format[i] == '.')
			i = ft_dot(tab, format, i + 1);
		if (format[i] == ' ' && ++i)
			tab->space = 1;
		if (format[i] == '#' && ++i)
			tab->form_hex = 1;
		if (format[i] == '+' && ++i)
			tab->sign = 1;
	}
	i = ft_get_argument(tab, format, i);
	ft_reset_tab(tab);
	return (i);
}
