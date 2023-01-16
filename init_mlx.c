/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:37:41 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/16 18:01:50 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_long *sl)
{
	sl->mlx_ptr = mlx_init();
	sl->mlx_win = mlx_new_window(sl->mlx_ptr, sl->length * 32, \
	sl->width * 32, "42 so_long thmeyer");
	fill_background(sl);
	put_img_to_map(sl);
	put_exit_and_start(sl);
	init_move(sl);
	sl->x = 1;
	sl->y = 3;
	mlx_hook(sl->mlx_win, 2, 1l << 0, check_keycode, sl);
	mlx_loop(sl->mlx_ptr);
}

void	put_img_to_map(t_long *sl)
{
	int		i;
	int		j;

	i = -1;
	sl->bush.img = mlx_xpm_file_to_image(sl->mlx_ptr, "Images/bush.xpm", \
	&sl->img_width, &sl->img_height);
	sl->collec.img = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"Images/ball.xpm", &sl->img_width, &sl->img_height);
	while (sl->map[++i])
	{
		j = -1;
		while (sl->map[i][++j])
		{
			if (sl->map[i][j] == '0')
				mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, \
				sl->bush.img, j * 32, i * 32);
			else if (sl->map[i][j] == 'C')
				mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, \
				sl->collec.img, j * 32, i * 32);
		}
	}
}

void	fill_background(t_long *sl)
{
	int		i;
	int		j;

	i = -1;
	sl->background.img = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"Images/background.xpm", &sl->img_width, &sl->img_height);
	sl->tree.img = mlx_xpm_file_to_image(sl->mlx_ptr, "Images/tree2.xpm", \
	&sl->img_width, &sl->img_height);
	while (sl->map[++i])
	{
		j = -1;
		while (sl->map[i][++j])
		{
			mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, \
			sl->background.img, j * 32, i * 32);
			if (sl->map[i][j] == '1')
				mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, \
				sl->tree.img, j * 32, i * 32);
		}
	}
}

void	put_exit_and_start(t_long *sl)
{
	int		i;
	int		j;

	i = -1;
	sl->exit.img = mlx_xpm_file_to_image(sl->mlx_ptr, "Images/bush.xpm", \
	&sl->img_width, &sl->img_height);
	sl->start.img = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"Images/start.xpm", &sl->img_width, &sl->img_height);
	while (sl->map[++i])
	{
		j = -1;
		while (sl->map[i][++j])
		{
			if (sl->map[i][j] == 'P')
				mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, \
				sl->start.img, j * 32, i * 32);
			else if (sl->map[i][j] == 'E')
				mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_win, \
				sl->exit.img, j * 32, i * 32);
		}
	}
}

void	init_move(t_long *sl)
{
	sl->up.img = mlx_xpm_file_to_image(sl->mlx_ptr, "Images/up.xpm", \
	&sl->img_width, &sl->img_height);
	sl->up2.img = mlx_xpm_file_to_image(sl->mlx_ptr, "Images/up2.xpm", \
	&sl->img_width, &sl->img_height);
	sl->bottom.img = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"Images/bottom.xpm", &sl->img_width, &sl->img_height);
	sl->bottom2.img = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"Images/bottom2.xpm", &sl->img_width, &sl->img_height);
	sl->left.img = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"Images/left.xpm", &sl->img_width, &sl->img_height);
	sl->left2.img = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"Images/left2.xpm", &sl->img_width, &sl->img_height);
	sl->right.img = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"Images/right.xpm", &sl->img_width, &sl->img_height);
	sl->right2.img = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"Images/right2.xpm", &sl->img_width, &sl->img_height);
}
