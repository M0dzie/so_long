/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:39:21 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/13 18:49:03 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **mapping, int size)
{
	int		i;
	int		j;
	char	*line;
	char	**map_cpy;

	i = -1;
	map_cpy = ft_calloc(size + 1, sizeof(char *));
	if (!map_cpy)
		exit(0);
	while (mapping[++i])
	{
		j = 0;
		line = ft_calloc(ft_strlen(mapping[i]) + 1, sizeof(char));
		while (mapping[i][j] != '\0')
		{
			line[j] = mapping[i][j];
			j++;
		}
		map_cpy[i] = line;
	}
	return (map_cpy);
}

void	fill_map(char *argv, int size, t_map **map)
{
	int		i;
	int		fd;
	char	*line;
	char	**mapping;

	i = -1;
	fd = open(argv, O_RDONLY);
	mapping = ft_calloc(size + 1, sizeof(char *));
	if (!mapping)
		exit(0);
	while (size - ++i > 0)
	{
		line = get_next_line(fd);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		mapping[i] = line;
	}
	check_walls(mapping, size);
	*map = map_new(mapping);
	(*map)->map_cpy = map_new(copy_map(mapping, size));
	elements_count(map, size);
	back_tracking(map, (*map)->x, (*map)->y);
	back_tracking_error(map);
	free(line);
	close(fd);
}
