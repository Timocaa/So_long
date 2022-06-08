/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:25:26 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 15:32:05 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_open_img(t_vars *v)
{
	int	pix;

	v->back = mlx_xpm_file_to_image(v->mlx, "img/back.xpm", &v->w_i, &v->h_i);
	v->wall = mlx_xpm_file_to_image(v->mlx, "img/wall.xpm", &pix, &pix);
	v->end = mlx_xpm_file_to_image(v->mlx, "img/out.xpm", &pix, &pix);
	v->back2 = mlx_xpm_file_to_image(v->mlx, "img/back2.xpm", &pix, &pix);
	v->item.it0 = mlx_xpm_file_to_image(v->mlx, "img/item.xpm", &pix,
			&pix);
	v->item.it1 = mlx_xpm_file_to_image(v->mlx, "img/item1.xpm", &pix,
			&pix);
	v->pnj.pnj0 = mlx_xpm_file_to_image(v->mlx, "img/pnj.xpm", &pix,
			&pix);
	v->pnj.pnj1 = mlx_xpm_file_to_image(v->mlx, "img/pnj1.xpm", &pix,
			&pix);
	v->pnj.pnjl0 = mlx_xpm_file_to_image(v->mlx, "img/pnjl.xpm", &pix,
			&pix);
	v->pnj.pnjl1 = mlx_xpm_file_to_image(v->mlx, "img/pnjl1.xpm", &pix,
			&pix);
	ft_img_player(v);
}

void	ft_img_player(t_vars *v)
{
	int	pix;

	v->player.pl0 = mlx_xpm_file_to_image(v->mlx, "img/play.xpm", &pix,
			&pix);
	v->player.plb = mlx_xpm_file_to_image(v->mlx, "img/playb.xpm", &pix,
			&pix);
	v->player.plf0 = mlx_xpm_file_to_image(v->mlx, "img/playf.xpm", &pix,
			&pix);
	v->player.pll0 = mlx_xpm_file_to_image(v->mlx, "img/playl.xpm", &pix,
			&pix);
}
