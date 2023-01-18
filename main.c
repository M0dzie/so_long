/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/18 12:15:37 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	free_struct(t_long *sl)
// {
// 	if (sl->mlx_ptr != NULL)
// 		mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
// 	free_tab(sl->map);
// 	free_tab(sl->map_cpy->map);
// }

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
	ft_printf("x : %d et y : %d\n", sl.x, sl.y);
	ft_printf("count_c : %d\n", sl.count_c);
	init_mlx(&sl);
	return (0);
}
