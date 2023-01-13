/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/13 19:26:22 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **mapping, char *type)
{
	int	i;

	i = 0;
	ft_printf("%s\n", type);
	while (mapping[i])
	{
		ft_printf("%s\n", mapping[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int		size;
	t_map	*map;
	t_init	mlx;

	if (argc != 2)
		display_error(6);
	valid_map(argv[1]);
	size = map_size(argv[1]);
	fill_map(argv[1], size, &map);
	//check_global;
	map->width = size;
	map->length = ft_strlen(map->mapping[0]);
	ft_printf("x : %d et y : %d\n", map->length, map->width);
	init_mlx(&map, &mlx);
	return (0);
}
