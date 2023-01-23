/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/23 11:45:25 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map, char *type)
{
	int	i;

	i = 0;
	ft_printf("%s\n", type);
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	ft_printf("\n");
}

void	free_struct(t_long *sl)
{
	free_tab(sl->map);
	mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
	mlx_destroy_image(sl->mlx_ptr, sl->background.img);
	mlx_destroy_image(sl->mlx_ptr, sl->bush.img);
	mlx_destroy_image(sl->mlx_ptr, sl->collec.img);
	mlx_destroy_image(sl->mlx_ptr, sl->down2.img);
	mlx_destroy_image(sl->mlx_ptr, sl->down.img);
	mlx_destroy_image(sl->mlx_ptr, sl->up.img);
	mlx_destroy_image(sl->mlx_ptr, sl->up2.img);
	mlx_destroy_image(sl->mlx_ptr, sl->right.img);
	mlx_destroy_image(sl->mlx_ptr, sl->right2.img);
	mlx_destroy_image(sl->mlx_ptr, sl->left.img);
	mlx_destroy_image(sl->mlx_ptr, sl->left2.img);
	mlx_destroy_image(sl->mlx_ptr, sl->start.img);
	mlx_destroy_image(sl->mlx_ptr, sl->exit.img);
	mlx_destroy_image(sl->mlx_ptr, sl->tree.img);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		size;
	t_long	sl;

	if (argc != 2)
		display_error(6);
	valid_map(argv[1]);
	size = map_size(argv[1]);
	sl = fill_map(argv[1], size, &sl);
	sl.width = size;
	sl.length = ft_strlen(sl.map[0]);
	init_mlx(&sl);
	return (0);
}
