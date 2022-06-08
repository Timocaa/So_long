/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:08:37 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 18:03:53 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_move_player(int keycode, t_vars *v)
{
	if (keycode == XK_w)
		ft_move(v, 0, -1);
	else if (keycode == XK_s)
		ft_move(v, 0, 1);
	else if (keycode == XK_d)
		ft_move(v, 1, 0);
	else if (keycode == XK_a)
		ft_move(v, -1, 0);
	return (1);
}

void	ft_move(t_vars *v, int x, int y)
{
	if (v->map[y + v->y][x + v->x] == '0' || v->map[y + v->y][x + v->x] == 'P')
		ft_print_move(v, x, y);
	else if (v->map[y + v->y][x + v->x] == 'C')
	{
		v->nb_i--;
		ft_print_move(v, x, y);
	}
	else if (v->map[y + v->y][x + v->x] == 'E')
	{
		if (v->nb_i == 0)
		{
			ft_print_move(v, x, y);
			ft_close2(v);
		}
	}
}

void	ft_print_move(t_vars *v, int x, int y)
{
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->back2, v->x * PIXEL,
		v->y * PIXEL);
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->play, (v->x + x) * PIXEL,
		(v->y + y) * PIXEL);
	v->map[v->y + y][v->x + x] = 'P';
	v->map[v->y][v->x] = '0';
	v->x += x;
	v->y += y;
	v->nb_m++;
	ft_printf("%d\n", v->nb_m);
}
