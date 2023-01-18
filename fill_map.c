/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:39:21 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/18 09:06:24 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, int size)
{
	int		i;
	int		j;
	char	*line;
	char	**map_cpy;

	i = -1;
	map_cpy = ft_calloc(size + 1, sizeof(char *));
	if (!map_cpy)
		exit(0);
	while (map[++i])
	{
		j = 0;
		line = ft_calloc(ft_strlen(map[i]) + 1, sizeof(char));
		if (!line)
			exit(0);
		while (map[i][j] != '\0')
		{
			line[j] = map[i][j];
			j++;
		}
		map_cpy[i] = line;
	}
	return (map_cpy);
}

t_long	fill_map(char *argv, int size, t_long *sl)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	fd = open(argv, O_RDONLY);
	sl->map = ft_calloc(size + 1, sizeof(char *));
	if (!sl->map)
		exit(0);
	while (size - ++i > 0)
	{
		line = get_next_line(fd);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		sl->map[i] = line;
	}
	check_walls(sl->map, size);
	sl = map_new(sl->map);
	sl->map_cpy = map_new(copy_map(sl->map, size));
	elements_count(sl, size);
	back_tracking(sl, sl->x, sl->y);
	back_tracking_error(sl);
	close (fd);
	return ((*sl));
}
