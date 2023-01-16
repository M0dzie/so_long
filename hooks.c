/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:29:03 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/16 18:36:50 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_keycode(int keycode, t_long *sl)
{
	if (keycode == 53)
		exit_win(sl);
	else
		move_char(keycode, sl);
	return (0);
}

int	exit_win(t_long *sl)
{
	mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
	//free_struct
	exit(0);
}

void	replace_lastcase(t_long *sl, int x, int y)
{
	mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, sl->background.img, \
	x * 32, y * 32);
	mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, sl->bush.img, \
	x * 32, y * 32);
}

int	move_char(int keycode, t_long *sl)
{
	if (keycode == 13 && sl->map[sl->y - 1][sl->x] != '1')
	{
		replace_lastcase(sl, sl->y, sl->x);
		sl->y -= 1;
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, \
		sl->up.img, sl->x * 32, sl->y * 32);
	}
	if (keycode == 2 && sl->map[sl->y][sl->x + 1] != '1')
	{		
		replace_lastcase(sl, sl->y, sl->x);
		sl->x += 1;
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, \
		sl->right.img, sl->x * 32, sl->y * 32);
	}
	if (keycode == 1 && sl->map[sl->y + 1][sl->x] != '1')
	{		
		replace_lastcase(sl, sl->y, sl->x);
		sl->y += 1;
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, \
		sl->bottom.img, sl->x * 32, sl->y * 32);
	}
	if (keycode == 0 && sl->map[sl->y][sl->x - 1] != '1')
	{		
		replace_lastcase(sl, sl->y, sl->x);
		sl->x -= 1;
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, \
		sl->left.img, sl->x * 32, sl->y * 32);
	}
	ft_printf("%d\n", sl->count_m += 1);
	return (0);
}
