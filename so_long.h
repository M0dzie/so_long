/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:58:34 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/10 18:24:09 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include "Minilibx/mlx.h"
# include <fcntl.h>

int		map_size(char *argv);

char	**fill_map(char *argv, int size);

size_t	sl_len(char *str);

void	display_error(int type);
void	valid_map(char *argv);

#endif