/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:24:26 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 17:00:43 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_print_error(char *str)
{
	write(2, "\033[31m   ", 8);
	write(2, str, ft_strlen(str));
	write(2, "\033[0m", 4);
}

int	ft_close2(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_clear_window(vars->mlx, vars->mlx_win);
	ft_destroy_img(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	while (i < vars->h_map + 1)
		free(vars->map[i++]);
	free(vars->map);
	exit(1);
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	int	i;

	i = 0;
	if (keycode == XK_Escape || keycode == XK_q)
	{
		mlx_clear_window(vars->mlx, vars->mlx_win);
		ft_destroy_img(vars);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		while (i < vars->h_map + 1)
			free(vars->map[i++]);
		free(vars->map);
		exit(1);
	}
	return (1);
}

void	ft_destroy_img(t_vars *v)
{
	mlx_destroy_image(v->mlx, v->back);
	mlx_destroy_image(v->mlx, v->wall);
	mlx_destroy_image(v->mlx, v->end);
	mlx_destroy_image(v->mlx, v->player.pl0);
	mlx_destroy_image(v->mlx, v->player.plb);
	mlx_destroy_image(v->mlx, v->player.plf0);
	mlx_destroy_image(v->mlx, v->player.pll0);
	mlx_destroy_image(v->mlx, v->item.it0);
	mlx_destroy_image(v->mlx, v->item.it1);
	mlx_destroy_image(v->mlx, v->pnj.pnj0);
	mlx_destroy_image(v->mlx, v->pnj.pnj1);
	mlx_destroy_image(v->mlx, v->pnj.pnjl0);
	mlx_destroy_image(v->mlx, v->pnj.pnjl1);
	mlx_destroy_image(v->mlx, v->back2);
}
