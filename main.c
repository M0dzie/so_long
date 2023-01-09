/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/09 17:43:13 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
#include "Libft/libft.h"
#include <stdio.h>

void	display_error(int type)
{
	if (type == 1)
		ft_putendl_fd("Error\nThe map must be rectangular.", 2);
	if (type == 2)
		ft_putendl_fd("Error\nThe map is not surrounded by walls.", 2);
	if (type == 3)
		ft_putendl_fd("Error\nNo valid path in the map.", 2);
	if (type == 4)
		ft_putendl_fd("Error\nThe map must contain 1 exit and 1 start.", 2);
	if (type == 5)
		ft_putendl_fd("Error\nThe map must contain at least 1 collectible.", 2);
	if (type == 6)
		ft_putendl_fd("Error\nThe program take only 1 map as parameter.", 2);
	if (type == 7)
		ft_putendl_fd("Error\nThe map is not valid.", 2);
	exit (0);
}

void	is_a_map(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '.' && argv[i + 1] == 'b' && argv[i + 2] == 'e'
			&& argv[i + 3] == 'r' && argv[i + 4] == '\0'
			&& ft_isprint(argv[i - 1]))
			return ;
	}
	display_error(7);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		display_error(6);
	is_a_map(argv[1]);
	return (0);
}
