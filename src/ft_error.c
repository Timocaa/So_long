/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:24:26 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/02 15:33:28 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	mlx_destroy_image(vars->mlx, vars->back);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->end);
	mlx_destroy_image(vars->mlx, vars->play);
	mlx_destroy_image(vars->mlx, vars->item);
	mlx_destroy_image(vars->mlx, vars->back2);
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
		mlx_destroy_image(vars->mlx, vars->back);
		mlx_destroy_image(vars->mlx, vars->wall);
		mlx_destroy_image(vars->mlx, vars->end);
		mlx_destroy_image(vars->mlx, vars->play);
		mlx_destroy_image(vars->mlx, vars->item);
		mlx_destroy_image(vars->mlx, vars->back2);
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
