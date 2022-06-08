/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:24:18 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 16:51:47 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_update(t_vars *v)
{
	static int	rate;

	if (rate == 150)
	{
		ft_anim_item(v);
		ft_anim_pnj(v);
		ft_update_map(v);
		rate = 0;
	}
	ft_put_result(v);
	rate++;
	return (1);
}

void	ft_anim_item(t_vars *v)
{
	static int	frame;

	if (v->item.frame_i == 0)
		return ;
	if (frame == v->item.frame_i)
		v->item.cur_i = 0;
	else if (frame >= v->item.frame_i * 2)
	{
		v->item.cur_i = 1;
		frame = 0;
	}
	frame += 1;
}

void	ft_anim_pnj(t_vars *v)
{
	static int	frame;

	if (v->pnj.anim == 0)
		return ;
	if (frame == v->pnj.anim)
		v->pnj.cur_img = 0;
	else if (frame >= v->pnj.anim * 2)
	{
		v->pnj.cur_img = 1;
		ft_move_pnj(v);
		frame = 0;
	}
	frame += 1;
}

void	ft_put_result(t_vars *v)
{
	char	*str;
	char	*nb;

	nb = ft_itoa(v->nb_m);
	str = ft_strjoin("MOVE : ", nb);
	mlx_string_put(v->mlx, v->mlx_win, P / 4, P / 2, 0x00ffffff, str);
	free(str);
	free(nb);
}
