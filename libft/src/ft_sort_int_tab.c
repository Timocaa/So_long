/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:31:09 by tlafont           #+#    #+#             */
/*   Updated: 2022/05/09 10:32:04 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	a;
	int	b;

	a = 0;
	while (a < size)
	{
		b = a;
		while (b < size)
		{
			if (tab[b] < tab[a])
			{
				temp = tab[a];
				tab[a] = tab[b];
				tab[b] = temp;
			}
			b++;
		}
		a++;
	}
}
