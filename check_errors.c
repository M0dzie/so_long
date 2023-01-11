/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:23 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/11 11:00:24 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (type == 9)
		ft_putendl_fd("Error\nThe map is empty.", 2);
	exit (1);
}

int	map_size(char *argv)
{
	int		fd;
	int		size;
	char	*line;
	size_t	len;

	size = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		display_error(8);
	line = get_next_line(fd);
	if (!line)
		display_error(9);
	len = sl_len(line);
	while (line)
	{
		if (len != sl_len(line))
			display_error(1);
		line = get_next_line(fd);
		size++;
	}
	if (size < 3)
		display_error(3);
	return (size);
}

void	valid_map(char *argv)
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

void	check_walls(char **map, int size)
{
	int	i;
	int	len;

	i = 0;
	if (size > 0)
	{
		while (map[size - 1][i])
		{
			if (map[size - 1][i] != '1')
				display_error(2);
			i++;
		}
		size--;
	}
	while (size > 1)
	{
		len = ft_strlen(map[size]);
		if (map[size - 1][0] != '1' && map[size - 1][len] != '1')
			display_error(2);
		size--;
	}
	if (size == 1)
		check_walls(map, size);
}
