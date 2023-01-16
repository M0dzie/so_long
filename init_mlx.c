/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:37:41 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/16 11:12:16 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	mlx_clear_window(void *mlx_ptr, void *win_ptr)
// {	
// }

// int	mlx_destroy_window(void *mlx_ptr, void *win_ptr)
// {
// }

// int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
// {
// }

// int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)
// {
// }

void	init_mlx(t_long *sl)
{
	print_map(sl->mapping, "Real Map");
	sl->mlx_ptr = mlx_init();
	print_map(sl->mapping, "MAP DE MERDE");
	sl->mlx_win = mlx_new_window(sl->mlx_ptr, sl->length * 32, \
	sl->width * 32, "42 so_long thmeyer");
	fill_background(&sl);
	put_img_to_map(&sl);
	put_exit_and_start(&sl);
	mlx_loop(sl->mlx_ptr);
	mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
	free(sl->mlx_ptr);
}

void	put_img_to_map(t_long **sl)
{
	int		i;
	int		j;
	t_long	bush;
	t_long	ball;

	i = -1;
	bush.img = mlx_xpm_file_to_image((*sl)->mlx_ptr, "Images/bush.xpm", \
	&(*sl)->img_width, &(*sl)->img_height);
	ball.img = mlx_xpm_file_to_image((*sl)->mlx_ptr, "Images/ball.xpm", \
	&(*sl)->img_width, &(*sl)->img_height);
	while ((*sl)->mapping[++i])
	{
		j = -1;
		while ((*sl)->mapping[i][++j])
		{
			if ((*sl)->mapping[i][j] == '0')
				mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
				bush.img, j * 32, i * 32);
			else if ((*sl)->mapping[i][j] == 'C')
				mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
				ball.img, j * 32, i * 32);
		}
	}
}

void	fill_background(t_long **sl)
{
	int		i;
	int		j;
	t_long	tree;
	t_long	background;

	i = -1;
	background.img = mlx_xpm_file_to_image((*sl)->mlx_ptr, \
	"Images/background.xpm", &(*sl)->img_width, &(*sl)->img_height);
	tree.img = mlx_xpm_file_to_image((*sl)->mlx_ptr, "Images/tree2.xpm", \
	&(*sl)->img_width, &(*sl)->img_height);
	while ((*sl)->mapping[++i])
	{
		j = -1;
		while ((*sl)->mapping[i][++j])
		{
			mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
			background.img, j * 32, i * 32);
			if ((*sl)->mapping[i][j] == '1')
				mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
				tree.img, j * 32, i * 32);
		}
	}
}

void	put_exit_and_start(t_long **sl)
{
	int		i;
	int		j;
	t_long	exit;
	t_long	start;

	i = -1;
	exit.img = mlx_xpm_file_to_image((*sl)->mlx_ptr, "Images/home.xpm", \
	&(*sl)->img_width, &(*sl)->img_height);
	start.img = mlx_xpm_file_to_image((*sl)->mlx_ptr, "Images/start.xpm", \
	&(*sl)->img_width, &(*sl)->img_height);
	while ((*sl)->mapping[++i])
	{
		j = -1;
		while ((*sl)->mapping[i][++j])
		{
			if ((*sl)->mapping[i][j] == 'P')
				mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
				start.img, j * 32, i * 32);
			else if ((*sl)->mapping[i][j] == 'E')
				mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
				exit.img, j * 32, i * 32);
		}
	}
}
