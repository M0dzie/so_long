/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin42@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/17 14:47:35 by thmeyer          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		size;
	t_long	sl;

	if (argc != 2)
		display_error(6);
	valid_map(argv[1]);
	size = map_size(argv[1]);
	fill_map(argv[1], size, &sl);
	ft_printf("x : %d et y : %d\ncount_m : %d et current_c : %d\n", sl.x, sl.y, sl.count_m, sl.current_c);
	//check_global;
	sl.width = size;
	sl.length = ft_strlen(sl.map[0]);
	sl.current_c = 0;
	sl.count_c = 2;
	sl.count_m = 0;
	sl.x = 1;
	sl.y = 3;
	ft_printf("x : %d et y : %d\ncount_m : %d et current_c : %d\n", sl.x, sl.y, sl.count_m, sl.current_c);
	init_mlx(&sl);
	// free_struct
	return (0);
}

// int	checkifgood(char c)
// {
// 	if (c != '0' && c != 'a' && c != '1' && c != 'P' && c != 'c' && c != 'E'
// 		&& c != 'd' && c != 'C' && c != 'e')
// 		return (0);
// 	return (1);
// }

// int	freeandexit(t_long *sl)
// {
// 	if (sl->mlx_ptr != NULL)
// 		mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
// 	freemap(sl);
// 	write(1, "\n\033[31m[ so_long closed successfully ]\n", 39);
// 	exit(0);
// }

// int	freemap(t_long *sl)
// {
// 	int	i;

// 	i = 0;
// 	if (sl->maptofree == -1)
// 		return (1);
// 	while (i < sl->y)
// 	{
// 		free(sl->map[i]);
// 		i++;
// 	}
// 	if (sl->map)
// 		free(sl->map);
// 	return (1);
// }