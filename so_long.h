/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:58:34 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/23 17:39:10 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include "Minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_img
{
	void	*img;
}			t_img;

typedef struct s_long
{
	void			*mlx_ptr;
	void			*mlx_win;

	char			**map;

	int				x;
	int				y;
	int				width;
	int				length;
	int				status;
	int				count_c;
	int				count_p;
	int				count_e;
	int				count_m;
	int				current_c;
	int				img_width;
	int				img_height;

	t_img			exit;
	t_img			bush;
	t_img			tree;
	t_img			start;
	t_img			collec;
	t_img			background;

	t_img			up;
	t_img			up2;
	t_img			left;
	t_img			down;
	t_img			right;
	t_img			left2;
	t_img			down2;
	t_img			right2;

	struct s_long	*map_cpy;
}					t_long;

char	**copy_map(char **map, int size);

int		check_keycode(int keycode, t_long *sl);
int		free_struct(t_long *sl);
int		map_size(char *argv);
int		move_y(int keycode, t_long *sl);
int		move_x(int keycode, t_long *sl);

size_t	sl_len(char *str);

t_long	fill_map(char *argv, int size, t_long *sl);
t_long	*map_new(char **map);

void	back_tracking(t_long *sl, int x, int y);
void	back_tracking_error(t_long *sl);
void	check_if_good(t_long *sl, char c);
void	check_place(t_long *sl);
void	check_walls(char **map, int size);
void	display_error(int type);
void	display_img_lastpos(t_long *sl);
void	elements_count(t_long *sl, int size);
void	fill_background(t_long *sl);
void	init_mlx(t_long *sl);
void	init_move(t_long *sl);
void	move_in_map(t_long *sl, int x, int y);
void	put_exit_and_start(t_long *sl);
void	put_img_to_map(t_long *sl);
void	valid_map(char *argv);

#endif