/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:02:30 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/13 16:36:47 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	back_tracking(t_map **map, int x, int y)
{
	int	count;

	count = 0;
	// ft_printf("\nx : %d et y : %d\n", x, y);
	// print_map((*map)->map_cpy->mapping, "Map Copy");
	move_in_map(map, x, y);
	if ((*map)->map_cpy->mapping[y - 1][x] != '1')
		back_tracking(map, x, y - 1);
	if ((*map)->map_cpy->mapping[y][x + 1] != '1')
		back_tracking(map, x + 1, y);
	if ((*map)->map_cpy->mapping[y + 1][x] != '1')
		back_tracking(map, x, y + 1);
	if ((*map)->map_cpy->mapping[y][x - 1] != '1')
		back_tracking(map, x - 1, y);
}

void	move_in_map(t_map **map, int x, int y)
{
	if ((*map)->map_cpy->mapping[y][x] == 'C')
		(*map)->map_cpy->count_c++;
	(*map)->map_cpy->mapping[y][x] = '1';
}

void	back_tracking_error(t_map **map)
{
	if ((*map)->count_c != (*map)->map_cpy->count_c)
		display_error(3);
}
