/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:16:42 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:50:33 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (s[0] == '\0')
		tmp = (char *)malloc(1);
	else
		tmp = (char *)malloc(sizeof(*tmp) * (ft_strlen(s) + 1));
	if (tmp == NULL)
		return (NULL);
	while (s[i])
	{
		tmp[i] = (*f)(s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
