/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin42@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:58:34 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/14 15:06:45 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include "Minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	char			**mapping;
	int				count_c;
	int				count_p;
	int				count_e;
	int				width;
	int				length;
	int				x;
	int				y;
	struct s_map	*map_cpy;
	struct s_map	*next;
}					t_map;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_init
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			img_width;
	int			img_height;
}				t_init;

int		map_size(char *argv);

char	**copy_map(char **mapping, int size);

size_t	sl_len(char *str);

t_map	*map_new(char **map);

void	back_tracking(t_map **map, int x, int y);
void	back_tracking_error(t_map **map);
void	check_walls(char **mapping, int size);
void	display_error(int type);
void	elements_count(t_map **map, int size);
void	fill_background(t_map **map, t_init *mlx);
void	fill_map(char *argv, int size, t_map **map);
void	init_mlx(t_map **map, t_init *mlx);
void	move_in_map(t_map **map, int x, int y);
void	put_exit_and_start(t_map **map, t_init *mlx);
void	put_img_to_map(t_map **map, t_init *mlx);
void	valid_map(char *argv);


void	print_map(char **mapping, char *type);

#endif