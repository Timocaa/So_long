/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:37:06 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 15:33:12 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_update_map(t_vars *v)
{
	int	x;
	int	y;

	mlx_clear_window(v->mlx, v->mlx_win);
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->back, 0, 0);
	x = 0;
	while (x * P < v->l_map * P)
	{
		y = 0;
		while (y * P < v->h_map * P)
		{
			ft_update_img(v, x, y);
			y++;
		}
		x++;
	}
}

void	ft_update_img(t_vars *v, int x, int y)
{
	if (v->map[y][x] == '1')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->wall, x * P, y * P);
	if (v->map[y][x] == 'E')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->end, x * P, y * P);
	if (v->map[y][x] == 'P')
		ft_update_player(v, x, y);
	if (v->map[y][x] == 'C')
	{
		if (v->item.cur_i == 0)
			mlx_put_image_to_window(v->mlx, v->mlx_win, v->item.it0, x * P,
				y * P);
		else
			mlx_put_image_to_window(v->mlx, v->mlx_win, v->item.it1, x * P,
				y * P);
	}
	ft_update_pnj(v, x, y);
}

void	ft_update_pnj(t_vars *v, int x, int y)
{
	if (v->map[y][x] == 'I')
	{
		if (v->pnj.cur_img == 0)
		{
			if (v->pnj.dir == 0)
				mlx_put_image_to_window(v->mlx, v->mlx_win, v->pnj.pnj0, x * P,
					y * P);
			else
				mlx_put_image_to_window(v->mlx, v->mlx_win, v->pnj.pnjl0, x * P,
					y * P);
		}
		else
		{
			if (v->pnj.dir == 0)
				mlx_put_image_to_window(v->mlx, v->mlx_win, v->pnj.pnj1, x * P,
					y * P);
			else
				mlx_put_image_to_window(v->mlx, v->mlx_win, v->pnj.pnjl1, x * P,
					y * P);
		}
	}
}

void	ft_update_player(t_vars *v, int x, int y)
{
	if (v->player.cur == 1)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->player.plb, x * P,
			y * P);
	else if (v->player.cur == 2)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->player.plf0, x * P,
			y * P);
	else if (v->player.cur == 3)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->player.pl0, x * P,
			y * P);
	else if (v->player.cur == 4)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->player.pll0, x * P,
			y * P);
}
