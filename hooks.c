/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:29:03 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/18 08:51:18 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_keycode(int keycode, t_long *sl)
{
	if (keycode == 53)
	{
		mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
		exit(0);
		//free_struct
	}
	if (keycode == 13 && sl->map[sl->y - 1][sl->x] != '1')
		move_char(keycode, sl);
	if (keycode == 2 && sl->map[sl->y][sl->x + 1] != '1')
		move_char(keycode, sl);
	if (keycode == 1 && sl->map[sl->y + 1][sl->x] != '1')
		move_char(keycode, sl);
	if (keycode == 0 && sl->map[sl->y][sl->x - 1] != '1')
		move_char(keycode, sl);
	return (0);
}

void	check_place(t_long *sl)
{
	if (sl->map[sl->y][sl->x] == 'C')
	{
		sl->current_c++;
		sl->map[sl->y][sl->x] = '0';
		sl->bush.img = mlx_xpm_file_to_image(sl->mlx_ptr, "Images/bush.xpm", \
		&sl->img_width, &sl->img_height);
	}
	if (sl->map[sl->y][sl->x] == 'E')
	{
		if (sl->current_c == sl->count_c)
		{
			mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
			exit(0);
			// freeandexit(sl);
		}
	}
}

void	display_img(t_long *sl, int x, int y)
{
	if (sl->map[y][x] == 'E')
	{	
		mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, sl->background.img, \
		x * 32, y * 32);
		mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, sl->exit.img, \
		x * 32, y * 32);
		return ;
	}
	mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, sl->background.img, \
	x * 32, y * 32);
	mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, sl->bush.img, \
	x * 32, y * 32);
}

int	move_char(int keycode, t_long *sl)
{
	if (keycode == 13 && sl->map[sl->y - 1][sl->x] != '1')
	{
		display_img(sl, sl->x, sl->y);
		sl->y -= 1;
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, \
		sl->up.img, sl->x * 32, sl->y * 32);
	}
	if (keycode == 2 && sl->map[sl->y][sl->x + 1] != '1')
	{		
		display_img(sl, sl->x, sl->y);
		sl->x += 1;
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, \
		sl->right.img, sl->x * 32, sl->y * 32);
	}
	if (keycode == 1 && sl->map[sl->y + 1][sl->x] != '1')
	{		
		display_img(sl, sl->x, sl->y);
		sl->y += 1;
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, \
		sl->down.img, sl->x * 32, sl->y * 32);
	}
	if (keycode == 0 && sl->map[sl->y][sl->x - 1] != '1')
	{		
		display_img(sl, sl->x, sl->y);
		sl->x -= 1;
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, \
		sl->left.img, sl->x * 32, sl->y * 32);
	}
	ft_printf("%d\n", sl->count_m += 1);
	check_place(sl);
	return (0);
}
