/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/16 10:56:17 by thmeyer          ###   ########.fr       */
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
	t_long	sl;

	if (argc != 2)
		display_error(6);
	valid_map(argv[1]);
	size = map_size(argv[1]);
	fill_map(argv[1], size, &sl);
	//check_global;
	sl.width = size;
	sl.length = ft_strlen(sl.mapping[0]);
	ft_printf("x : %d et y : %d\n", sl.length, sl.width);
	init_mlx(&sl);
	return (free_tab(sl.mapping), 0);
}
