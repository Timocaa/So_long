/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:47:21 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:51:31 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (strncmp(s1, s2, n) != 0)
		return (0);
	else
		return (1);
}
