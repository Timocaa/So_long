/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:47:49 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:52:32 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(*sub) * 1);
		sub[0] = '\0';
		return (sub);
	}
	else if (start < ft_strlen(s) && (start + len) > ft_strlen(s))
		sub = (char *)malloc(sizeof(*sub) * ((ft_strlen(s) - start) + 1));
	else
		sub = (char *)malloc(sizeof(*sub) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
