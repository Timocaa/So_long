/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:44:36 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:36:21 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*block;

	if (nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	block = (void *)malloc(nmemb * size);
	if (block == NULL || (nmemb * size) > 2147483647)
		return (NULL);
	ft_bzero(block, (nmemb * size));
	return (block);
}
