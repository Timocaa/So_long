/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:43:58 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:46:57 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	ft_strcpy(&dest[i], src);
	return (dest);
}
