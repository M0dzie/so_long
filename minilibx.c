/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:37:41 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/13 11:44:35 by thmeyer          ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_mlx(t_map **map)
{
	void	*mlx;
	void	*mlx_win;
	char	*relative_path = "Images/tree.xpm";
	int		img_width;
	int		img_height;
	t_data	img;

	mlx = mlx_init();
	if (!mlx)
		exit(0);
	mlx_win = mlx_new_window(mlx, (*map)->length * 32, (*map)->width * 32, \
	"Pallet Town");
	if (!mlx_win)
		exit(0);
	// img.img = mlx_new_image(mlx, (*map)->length * 32, (*map)->width * 32);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, \
	&img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
