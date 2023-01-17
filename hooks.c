/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin42@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:29:03 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/17 15:50:25 by thmeyer          ###   ########.fr       */
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
		ft_printf("current_c : %d\n", sl->current_c);
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

void	display_img(t_long *sl, t_img *img)
{
	if (img == sl->up.img)
	{
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, img, \
		sl->x * 32, sl->y - 1 * 32);
		sl->y -= 1;
	}
	if (img == sl->down.img)
	{
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, img, \
		sl->x * 32, sl->y + 1 * 32);
		sl->y += 1;
	}
	if (img == sl->right.img)
	{
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, img, \
		sl->x + 1 * 32, sl->y * 32);
		sl->x += 1;
	}
	if (img == sl->left.img)
	{
		mlx_put_image_to_window (sl->mlx_ptr, sl->mlx_win, img, \
		sl->x - 1 * 32, sl->y * 32);
		sl->x -= 1;
	}
}

int	move_char(int keycode, t_long *sl)
{
	mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, sl->background.img, \
	sl->x * 32, sl->y * 32);
	mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, sl->bush.img, \
	sl->x * 32, sl->y * 32);
	if (keycode == 13)
		display_img(sl, sl->up.img);
	if (keycode == 2)
		display_img(sl, sl->right.img);
	if (keycode == 1)
		display_img(sl, sl->down.img);
	if (keycode == 0)
		display_img(sl, sl->left.img);
	ft_printf("%d\n", sl->count_m += 1);
	check_place(sl);
	return (0);
}
