/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:56:46 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:52:39 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_tolower(int c)
{
	if ((char)c >= 65 && (char)c <= 90)
		return (c += 32);
	else
		return (c);
}
