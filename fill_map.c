/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:39:21 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/16 11:14:31 by thmeyer          ###   ########.fr       */
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

void	fill_map(char *argv, int size, t_long *sl)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	fd = open(argv, O_RDONLY);
	sl->mapping = ft_calloc(size + 1, sizeof(char *));
	if (!sl->mapping)
		exit(0);
	while (size - ++i > 0)
	{
		line = get_next_line(fd);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		sl->mapping[i] = line;
	}
	check_walls(sl->mapping, size);
	sl = map_new(sl->mapping);
	sl->map_cpy = map_new(copy_map(sl->mapping, size));
	elements_count(&sl, size);
	back_tracking(&sl, sl->x, sl->y);
	back_tracking_error(&sl);
	close (fd);
}
