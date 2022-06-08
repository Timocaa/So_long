/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pnj_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:17:04 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 15:38:31 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_move_pnj(t_vars *v)
{
	ft_direction_pnj(v);
	ft_cross_item(v);
	if (v->pnj.dir == 0)
	{
		if (v->map[v->pnj.pnjy][v->pnj.pnjx + 1] == 'P')
			ft_game_over(v);
		else
			ft_print_move_pnj(v, 1);
	}
	else
	{
		if (v->map[v->pnj.pnjy][v->pnj.pnjx - 1] == 'P')
			ft_game_over(v);
		else
			ft_print_move_pnj(v, -1);
	}
}

void	ft_direction_pnj(t_vars *v)
{
	if (v->pnj.dir == 0)
	{
		if (v->map[v->pnj.pnjy][v->pnj.pnjx + 1] == '1' ||
			v->map[v->pnj.pnjy][v->pnj.pnjx + 1] == 'E')
			v->pnj.dir = 1;
		else
			v->pnj.dir = 0;
	}
	else
	{
		if (v->map[v->pnj.pnjy][v->pnj.pnjx - 1] == '1' ||
			v->map[v->pnj.pnjy][v->pnj.pnjx - 1] == 'E')
			v->pnj.dir = 0;
		else
			v->pnj.dir = 1;
	}
}

void	ft_cross_item(t_vars *v)
{
	int		x;

	if (v->pnj.dir == 0)
		x = 1;
	else
		x = -1;
	if (v->map[v->pnj.pnjy][v->pnj.pnjx + x] == 'C')
		v->cross = 2;
}

void	ft_print_move_pnj(t_vars *v, int x)
{
	if (v->cross == 0 || v->cross == 2)
	{
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->back2, v->pnj.pnjx * P,
			v->pnj.pnjy * P);
		v->map[v->pnj.pnjy][v->pnj.pnjx] = '0';
		v->pnj.pnjx += x;
		if (v->cross == 2)
			v->cross--;
		v->map[v->pnj.pnjy][v->pnj.pnjx] = 'I';
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->pnj.pnj0,
			((v->pnj.pnjx) * P), (v->pnj.pnjy) * P);
	}
	else
	{
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->item.it0,
			v->pnj.pnjx * P, v->pnj.pnjy * P);
		v->map[v->pnj.pnjy][v->pnj.pnjx] = 'C';
		v->pnj.pnjx += x;
		v->map[v->pnj.pnjy][v->pnj.pnjx] = 'I';
		v->cross = 0;
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->pnj.pnj0,
			((v->pnj.pnjx) * P), (v->pnj.pnjy) * P);
	}
}

void	ft_game_over(t_vars *v)
{
	ft_print_move_pnj(v, 1);
	ft_printf("GAME OVER !\n");
	usleep(500000);
	ft_close2(v);
}
