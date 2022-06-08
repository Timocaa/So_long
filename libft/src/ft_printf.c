/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:19:40 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:55:21 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printf(const char *format, ...)
{
	t_printf	*tab;
	int			i;
	int			total;

	if (format[0] == '\0')
		return (0);
	i = 0;
	total = 0;
	tab = (t_printf *)malloc(sizeof(*tab));
	if (tab == NULL)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			i = ft_check_flags(tab, format, i + 1);
		else
			total += write(1, &format[i], 1);
		i++;
	}
	va_end(tab->args);
	total += tab->tot_len;
	free(tab);
	return (total);
}
