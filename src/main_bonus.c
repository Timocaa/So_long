/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:43:26 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/08 13:28:05 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_chk	*item;
	t_vars	v;

	item = (t_chk *)calloc(sizeof(t_chk), 1);
	if (!ft_check_args(item, ac, av))
		return (free(item), 0);
	free(item);
	if (ft_init_game(&v, av[1]))
	{
		mlx_key_hook(v.mlx_win, ft_move_player, &v);
		mlx_loop_hook(v.mlx, ft_update, &v);
		mlx_hook(v.mlx_win, 2, 1L << 0, ft_close, &v);
		mlx_hook(v.mlx_win, DestroyNotify, 0, ft_close2, &v);
		mlx_loop(v.mlx);
	}
	return (0);
}

int	ft_pars_line(char *line, t_chk *item)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != '1' && line[j] != '0' && line[j] != 'E'
			&& line[j] != 'C' && line[j] != 'P' && line[j] != '\n'
			&& line[j] != 'I')
			return (0);
		if (line[j] == 'E')
			item->e++;
		if (line[j] == 'C')
			item->c++;
		if (line[j] == 'P')
			item->p++;
		if (line[j] == 'I')
			item->i++;
		if (line[j] == 'I' && line[j - 1] == '1' && line[j + 1] == '1')
			return (0);
		j++;
	}
	return (1);
}
