/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:58:34 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/11 15:19:09 by thmeyer          ###   ########.fr       */
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
	int				x;
	int				y;
	struct s_map	*next;
}					t_map;

typedef struct s_pos
{
	int				pos_x;
	int				pos_y;
	struct s_pos	*next;
}					t_pos;

int		map_size(char *argv);

size_t	sl_len(char *str);

// t_map	*map_last(t_map *map);
t_map	*map_new(char **map);

void	back_tracking(t_map **map);
void	check_walls(char **mapping, int size);
void	display_error(int type);
void	elements_count(t_map **map, int size);
void	fill_map(char *argv, int size, t_map **map);
// void	map_add_back(t_map **map, t_map *new);
void	valid_map(char *argv);


void	print_map(char **mapping);

#endif