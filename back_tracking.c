/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:02:30 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/18 17:09:30 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	back_tracking(t_long *sl, int x, int y)
{
	// ft_printf("\nx : %d et y : %d\n", x, y);
	// print_map(sl->map_cpy->map, "Map Copy");
	move_in_map(sl, x, y);
	if (sl->map_cpy->map[y - 1][x] != '1')
		back_tracking(sl, x, y - 1);
	if (sl->map_cpy->map[y][x + 1] != '1')
		back_tracking(sl, x + 1, y);
	if (sl->map_cpy->map[y + 1][x] != '1')
		back_tracking(sl, x, y + 1);
	if (sl->map_cpy->map[y][x - 1] != '1')
		back_tracking(sl, x - 1, y);
}

void	move_in_map(t_long *sl, int x, int y)
{
	check_if_good(sl, sl->map[y][x]);
	if (sl->map_cpy->map[y][x] == 'C')
		sl->map_cpy->count_c++;
	if (sl->map_cpy->map[y][x] == 'E')
		sl->map_cpy->count_e++;
	sl->map_cpy->map[y][x] = '1';
}

void	back_tracking_error(t_long *sl)
{
	if ((sl->count_c != sl->map_cpy->count_c) || (sl->count_e != \
	sl->map_cpy->count_e))
		return (free_struct(sl), display_error(3));
}
