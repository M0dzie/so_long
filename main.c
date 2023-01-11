/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:04:45 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/11 15:18:58 by thmeyer          ###   ########.fr       */
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

void	fill_map(char *argv, int size, t_map **map)
{
	int		i;
	int		fd;
	char	*line;
	char	**mapping;

	i = 0;
	fd = open(argv, O_RDONLY);
	mapping = ft_calloc(size + 1, sizeof(char *));
	if (!mapping)
		exit(0);
	while (size - i > 0)
	{
		line = get_next_line(fd);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		mapping[i] = line;
		i++;
	}
	check_walls(mapping, size);
	(*map) = map_new(mapping);
	elements_count(&(*map), size);
	free(line);
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
	print_map(map->mapping);
	back_tracking(&map);
	return (0);
}
