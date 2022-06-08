/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:08:37 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 16:56:13 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_move_player(int keycode, t_vars *v)
{
	if (keycode == XK_w)
		ft_move(v, 0, -1, 'w');
	else if (keycode == XK_s)
		ft_move(v, 0, 1, 's');
	else if (keycode == XK_d)
		ft_move(v, 1, 0, 'd');
	else if (keycode == XK_a)
		ft_move(v, -1, 0, 'a');
	return (1);
}

void	ft_move(t_vars *v, int x, int y, char dir)
{
	if (v->map[y + v->y][x + v->x] == '0' || v->map[y + v->y][x + v->x] == 'P')
		ft_print_move(v, x, y, dir);
	else if (v->map[y + v->y][x + v->x] == 'C')
	{
		v->nb_i--;
		ft_print_move(v, x, y, dir);
	}
	else if (v->map[y + v->y][x + v->x] == 'E')
	{
		if (v->nb_i == 0)
		{
			ft_print_move(v, x, y, dir);
			ft_close2(v);
		}
	}
	else if (v->map[y + v->y][x + v->x] == 'I')
	{
		ft_print_move(v, x, y, dir);
		ft_printf("GAME OVER !\n");
		usleep(500000);
		ft_close2(v);
	}
}

void	ft_print_move(t_vars *v, int x, int y, char dir)
{
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->back2, v->x * P,
		v->y * P);
	if (dir == 'w')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->player.plb,
			((v->x + x) * P), (v->y + y) * P);
	else if (dir == 's')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->player.plf0,
			((v->x + x) * P), (v->y + y) * P);
	else if (dir == 'd')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->player.pl0,
			((v->x + x) * P), (v->y + y) * P);
	else if (dir == 'a')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->player.pll0,
			((v->x + x) * P), (v->y + y) * P);
	ft_curent_img(v, dir);
	v->map[v->y + y][v->x + x] = 'P';
	v->map[v->y][v->x] = '0';
	v->x += x;
	v->y += y;
	v->nb_m++;
}

void	ft_curent_img(t_vars *v, char dir)
{
	if (dir == 'w')
		v->player.cur = 1;
	else if (dir == 's')
		v->player.cur = 2;
	else if (dir == 'd')
		v->player.cur = 3;
	else if (dir == 'a')
		v->player.cur = 4;
}
