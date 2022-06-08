/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:55:47 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/07 18:08:38 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/include/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define PIXEL 30

typedef struct s_chk
{
	int	c;
	int	e;
	int	p;
}	t_chk;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	void	*back;
	void	*back2;
	void	*wall;
	void	*play;
	void	*item;
	void	*end;
	int		pix;
	int		w_i;
	int		h_i;
	char	**map;
	int		h_map;
	int		l_map;
	int		h_w;
	int		l_w;
	int		x;
	int		y;
	int		nb_i;
	int		nb_m;
}	t_vars;

//--------------------- fct error -----------------------
void	ft_print_error(char *str);
//------------------- check errors ----------------------
int		ft_check_args(t_chk *item, int ac, char **av);
int		ft_parsing_map(t_chk *item, char *map);
int		ft_read_map(char *map);
int		ft_check_map(t_chk *item, int i, int fd);
int		ft_check_line(t_chk *item, int i, int max, char *line);
//---------------- fct initialisation -------------------
int		ft_init_game(t_vars *v, char *map);
int		ft_init_vars(t_vars *v, char *n_map);
int		ft_record_map(t_vars *v, char *n_map);
void	ft_init_map(t_vars *v);
void	ft_put_img(t_vars *v, int x, int y);
//--------------------- fct game ------------------------
int		ft_move_player(int keycode, t_vars *v);
void	ft_move(t_vars *v, int x, int y);
void	ft_print_move(t_vars *v, int x, int y);
//------------------- check errors ----------------------
int		ft_close(int keycode, t_vars *vars);
int		ft_close2(t_vars *vars);

#endif
