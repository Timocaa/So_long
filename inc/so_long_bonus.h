/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:55:47 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 16:48:02 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/include/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define P 30

typedef struct s_chk
{
	int	c;
	int	e;
	int	p;
	int	i;
}	t_chk;

typedef struct s_player
{
	void	*cur_img;
	int		frame_p;
	int		idle;
	int		cur;
	void	*pl0;
	void	*plb;
	void	*plf0;
	void	*pll0;
}	t_player;

typedef struct s_pnj
{
	int		cur_img;
	int		anim;
	void	*pnj0;
	void	*pnj1;
	void	*pnjl0;
	void	*pnjl1;
	int		dir;
	int		pnjx;
	int		pnjy;
}	t_pnj;

typedef struct s_item
{
	int		cur_i;
	int		frame_i;
	void	*it0;
	void	*it1;
}	t_item;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	void		*back;
	void		*back2;
	void		*wall;
	t_player	player;
	t_item		item;
	t_pnj		pnj;
	void		*end;
	int			cross;
	int			w_i;
	int			h_i;
	char		**map;
	int			h_map;
	int			l_map;
	int			h_w;
	int			l_w;
	int			x;
	int			y;
	int			nb_i;
	int			nb_m;
}	t_vars;

//--------------------- fct error -----------------------
void	ft_print_error(char *str);
//------------------- check errors ----------------------
int		ft_check_args(t_chk *item, int ac, char **av);
int		ft_parsing_map(t_chk *item, char *map);
int		ft_read_map(char *map);
int		ft_check_map(t_chk *item, int i, int fd);
int		ft_check_line(t_chk *item, int i, int max, char *line);
int		ft_pars_line(char *line, t_chk *item);
//---------------- fct initialisation -------------------
int		ft_init_game(t_vars *v, char *map);
int		ft_init_vars(t_vars *v, char *n_map);
int		ft_record_map(t_vars *v, char *n_map);
void	ft_open_img(t_vars *v);
void	ft_img_player(t_vars *v);
void	ft_init_map(t_vars *v);
void	ft_put_img(t_vars *v, int x, int y);
//--------------------- fct game ------------------------
int		ft_update(t_vars *v);
void	ft_anim_item(t_vars *v);
void	ft_update_map(t_vars *v);
void	ft_update_img(t_vars *v, int x, int y);
void	ft_anim_pnj(t_vars *v);
void	ft_update_pnj(t_vars *v, int x, int y);
void	ft_move_pnj(t_vars *v);
void	ft_direction_pnj(t_vars *v);
void	ft_cross_item(t_vars *v);
void	ft_print_move_pnj(t_vars *v, int x);
int		ft_move_player(int keycode, t_vars *v);
void	ft_move(t_vars *v, int x, int y, char dir);
void	ft_print_move(t_vars *v, int x, int y, char dir);
void	ft_curent_img(t_vars *v, char dir);
void	ft_update_player(t_vars *v, int x, int y);
void	ft_put_result(t_vars *v);
//------------------- close program ---------------------
int		ft_close(int keycode, t_vars *vars);
int		ft_close2(t_vars *vars);
void	ft_destroy_img(t_vars *v);
void	ft_game_over(t_vars *v);

#endif
