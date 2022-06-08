/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:14:54 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 18:05:01 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_init_game(t_vars *v, char *map)
{
	if (!ft_init_vars(v, map))
		return (0);
	v->mlx = mlx_init();
	v->mlx_win = mlx_new_window(v->mlx, v->l_w, v->h_w, "./so_long");
	v->back = mlx_xpm_file_to_image(v->mlx, "img/back.xpm", &v->w_i, &v->h_i);
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->back, 0, 0);
	ft_init_map(v);
	return (1);
}

int	ft_init_vars(t_vars *v, char *n_map)
{
	if (!ft_record_map(v, n_map))
		return (ft_print_error("Error\n     Record map failed !\n"), 0);
	v->l_w = v->l_map * PIXEL;
	v->h_w = v->h_map * PIXEL;
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

	v->wall = mlx_xpm_file_to_image(v->mlx, "img/wall.xpm", &v->pix, &v->pix);
	v->end = mlx_xpm_file_to_image(v->mlx, "img/out.xpm", &v->pix, &v->pix);
	v->item = mlx_xpm_file_to_image(v->mlx, "img/item.xpm", &v->pix, &v->pix);
	v->play = mlx_xpm_file_to_image(v->mlx, "img/play.xpm", &v->pix, &v->pix);
	v->back2 = mlx_xpm_file_to_image(v->mlx, "img/back2.xpm", &v->pix, &v->pix);
	x = 0;
	v->nb_i = 0;
	v->nb_m = 0;
	while (x * PIXEL < v->l_map * PIXEL)
	{
		y = 0;
		while (y * PIXEL < v->h_map * PIXEL)
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
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->wall, x * PIXEL,
			y * PIXEL);
	if (v->map[y][x] == 'E')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->end, x * PIXEL,
			y * PIXEL);
	if (v->map[y][x] == 'P')
	{
		v->x = x;
		v->y = y;
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->play, x * PIXEL,
			y * PIXEL);
	}
	if (v->map[y][x] == 'C')
	{
		v->nb_i++;
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->item, x * PIXEL,
			y * PIXEL);
	}
}
