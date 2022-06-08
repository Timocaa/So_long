/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:42:05 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:48:30 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(*cpy) * ft_strlen(s) + 1);
	if (cpy == NULL)
		return (NULL);
	ft_strcpy(cpy, s);
	return (cpy);
}
