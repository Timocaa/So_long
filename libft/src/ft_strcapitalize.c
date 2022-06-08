/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:35:22 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:45:51 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (word == 0 && str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
			word = 1;
		}
		else if (word > 0 && str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		else if (str[i] < 48 || (str[i] > 57 && str[i] < 65)
			|| (str[i] > 90 && str[i] < 97) || str[i] > 122)
			word = 0;
		else
			word++;
		i++;
	}
	return (str);
}
