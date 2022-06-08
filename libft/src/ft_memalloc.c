/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:38:59 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:41:47 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*block;

	block = (void *)malloc(sizeof(void) * size);
	if (block == NULL)
		return (NULL);
	else
	{
		ft_bzero(block, size);
		return (block);
	}
}
