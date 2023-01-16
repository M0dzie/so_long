/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:58:34 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/16 11:16:09 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include "Minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_long
{
	void			*img;
	void			*mlx_ptr;
	void			*mlx_win;
	char			*addr;
	char			**mapping;
	int				x;
	int				y;
	int				bpp;
	int				width;
	int				length;
	int				endian;
	int				count_c;
	int				count_p;
	int				count_e;
	int				img_width;
	int				img_height;
	int				line_length;
	struct s_long	*map_cpy;
	struct s_long	*next;
}					t_long;

int		map_size(char *argv);

char	**copy_map(char **mapping, int size);

size_t	sl_len(char *str);

t_long	*map_new(char **map);

void	back_tracking(t_long **sl, int x, int y);
void	back_tracking_error(t_long **sl);
void	check_walls(char **mapping, int size);
void	display_error(int type);
void	elements_count(t_long **sl, int size);
void	fill_background(t_long **sl);
void	fill_map(char *argv, int size, t_long *sl);
void	init_mlx(t_long *sl);
void	move_in_map(t_long **sl, int x, int y);
void	put_exit_and_start(t_long **sl);
void	put_img_to_map(t_long **sl);
void	valid_map(char *argv);

void	print_map(char **mapping, char *type);

#endif