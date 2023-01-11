/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/11 11:08:22 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	**fill_map(char *argv, int size)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	i = 0;
	fd = open(argv, O_RDONLY);
	map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		exit(1);
	while (size - i > 0)
	{
		line = get_next_line(fd);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
	}
	return (free(line), map);
}

int	main(int argc, char **argv)
{
	int		size;
	char	**map;

	if (argc != 2)
		display_error(6);
	valid_map(argv[1]);
	size = map_size(argv[1]);
	map = fill_map(argv[1], size);
	print_map(map);
	check_walls(map, size);
	return (0);
}
