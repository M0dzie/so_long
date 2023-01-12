/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/12 13:20:03 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **mapping)
{
	int	i;

	i = 0;
	while (mapping[i])
	{
		ft_printf("%s\n", mapping[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		size;
	t_map	*map;

	map = NULL;
	if (argc != 2)
		display_error(6);
	valid_map(argv[1]);
	size = map_size(argv[1]);
	fill_map(argv[1], size, &map);
	map->width = size;
	map->length = ft_strlen(map->mapping[0]);
	ft_printf("x : %d et y : %d", map->length, map->width);
	init_mlx(&map);
	return (0);
}
