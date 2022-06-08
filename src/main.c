/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:43:26 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/02 14:31:32 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		mlx_hook(v.mlx_win, 2, 1L << 0, ft_close, &v);
		mlx_hook(v.mlx_win, DestroyNotify, 0, ft_close2, &v);
		mlx_loop(v.mlx);
	}
	return (0);
}
