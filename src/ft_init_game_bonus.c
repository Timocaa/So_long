/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:14:54 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 15:32:32 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_init_game(t_vars *v, char *map)
{
	if (!ft_init_vars(v, map))
		return (0);
	v->mlx = mlx_init();
	v->mlx_win = mlx_new_window(v->mlx, v->l_w, v->h_w, "./so_long");
	ft_init_map(v);
	return (1);
}

int	ft_init_vars(t_vars *v, char *n_map)
{
	if (!ft_record_map(v, n_map))
		return (ft_print_error("Error\n     Record map failed !\n"), 0);
	v->l_w = v->l_map * P;
	v->h_w = v->h_map * P;
	v->player.idle = 17;
	v->item.frame_i = 25;
	v->pnj.anim = 25;
	return (1);
}

int	ft_record_map(t_vars *v, char *n_map)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	v->h_map = ft_read_map(n_map);
	v->map = (char **)malloc(sizeof(char *) * (v->h_map + 1));
	if (!v->map)
		return (0);
	fd = open(n_map, O_RDONLY);
	while (i < v->h_map)
	{
		line = get_next_line(fd);
		v->l_map = ft_strlen(line) - 1;
		v->map[i] = ft_strndup(line, v->l_map);
		free(line);
		i++;
	}
	v->map[i] = 0;
	return (1);
}

void	ft_init_map(t_vars *v)
{
	int	x;
	int	y;

	ft_open_img(v);
	x = 0;
	v->nb_i = 0;
	v->nb_m = 0;
	v->item.cur_i = 0;
	v->pnj.cur_img = 0;
	v->pnj.dir = 0;
	v->cross = 0;
	v->player.cur = 3;
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->back, 0, 0);
	while (x * P < v->l_map * P)
	{
		y = 0;
		while (y * P < v->h_map * P)
		{
			ft_put_img(v, x, y);
			y++;
		}
		x++;
	}
}

void	ft_put_img(t_vars *v, int x, int y)
{
	if (v->map[y][x] == '1')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->wall, x * P,
			y * P);
	if (v->map[y][x] == 'E')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->end, x * P,
			y * P);
	if (v->map[y][x] == 'P')
	{
		v->x = x;
		v->y = y;
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->player.pl0, x * P,
			y * P);
	}
	if (v->map[y][x] == 'C')
	{
		v->nb_i++;
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->item.it0, x * P, y * P);
	}
	if (v->map[y][x] == 'I')
	{
		v->pnj.pnjx = x;
		v->pnj.pnjy = y;
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->pnj.pnj0, x * P, y * P);
	}
}
