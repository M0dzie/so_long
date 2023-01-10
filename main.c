/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/10 17:11:10 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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
	if (type == 8)
		ft_putendl_fd("Error\nNo such file or directory.", 2);
	exit (0);
}

void	map_size(char *argv)
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		display_error(8);
	line = get_next_line(fd);
	printf("Maps : \n");
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		size++;
	}
	printf("\nsize : %d\n", size);
	// return (size);
}

void	is_a_valid_map(char *argv)
{
	char	*name;
	int		len;

	name = ft_strrchr(argv, '/');
	if (!name)
		name = argv;
	else
		name += 1;
	len = ft_strlen(name);
	if (len > 4)
	{
		name += len - 4;
		if (ft_strncmp(name, ".ber", 4) == 0)
			return ;
	}
	display_error(7);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		display_error(6);
	is_a_valid_map(argv[1]);
	map_size(argv[1]);
	return (0);
}
