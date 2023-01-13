/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:37:41 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/13 19:08:03 by thmeyer          ###   ########.fr       */
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

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	init_mlx(t_map **map, t_init *mlx)
{
	print_map((*map)->mapping, "Real Map");
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	print_map((*map)->mapping, "MAP DE MERDE");
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, (*map)->length * 32, \
	(*map)->width * 32, "Walking in the Forest");
	if (!mlx->mlx_ptr)
		return ;
	fill_background(map, mlx);
	put_img_to_map(map, mlx);
	put_exit_and_start(map, mlx);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	free(mlx->mlx_ptr);
}

void	put_img_to_map(t_map **map, t_init *mlx)
{
	int		i;
	int		j;
	t_data	bush;
	t_data	ball;

	i = -1;
	bush.img = mlx_xpm_file_to_image(mlx->mlx_ptr, "Images/bush.xpm", \
	&mlx->img_width, &mlx->img_height);
	ball.img = mlx_xpm_file_to_image(mlx->mlx_ptr, "Images/ball.xpm", \
	&mlx->img_width, &mlx->img_height);
	while ((*map)->mapping[++i])
	{
		j = -1;
		while ((*map)->mapping[i][++j])
		{
			if ((*map)->mapping[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				bush.img, j * 32, i * 32);
			else if ((*map)->mapping[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				ball.img, j * 32, i * 32);
		}
	}
}

void	fill_background(t_map **map, t_init *mlx)
{
	int		i;
	int		j;
	t_data	tree;
	t_data	background;

	i = -1;
	background.img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"Images/background.xpm", &mlx->img_width, &mlx->img_height);
	tree.img = mlx_xpm_file_to_image(mlx->mlx_ptr, "Images/tree2.xpm", \
	&mlx->img_width, &mlx->img_height);
	while ((*map)->mapping[++i])
	{
		j = -1;
		while ((*map)->mapping[i][++j])
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
			background.img, j * 32, i * 32);
			if ((*map)->mapping[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				tree.img, j * 32, i * 32);
		}
	}
}

void	put_exit_and_start(t_map **map, t_init *mlx)
{
	int		i;
	int		j;
	t_data	exit;
	t_data	start;

	i = -1;
	exit.img = mlx_xpm_file_to_image(mlx->mlx_ptr, "Images/home.xpm", \
	&mlx->img_width, &mlx->img_height);
	start.img = mlx_xpm_file_to_image(mlx->mlx_ptr, "Images/start.xpm", \
	&mlx->img_width, &mlx->img_height);
	while ((*map)->mapping[++i])
	{
		j = -1;
		while ((*map)->mapping[i][++j])
		{
			if ((*map)->mapping[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				start.img, j * 32, i * 32);
			else if ((*map)->mapping[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				exit.img, j * 32, i * 32);
		}
	}
}
