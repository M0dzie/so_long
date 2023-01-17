/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin42@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:23 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/17 13:35:35 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (close(fd), size);
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

void	elements_count(t_long *sl, int size)
{
	int	i;

	while (--size > 0)
	{
		i = -1;
		while (sl->map[size][++i])
		{
			if (sl->map[size][i] == 'C')
				sl->count_c++;
			else if (sl->map[size][i] == 'P')
			{
				sl->count_p++;
				sl->x = i;
				sl->y = size;
			}
			else if (sl->map[size][i] == 'E')
				sl->count_e++;
		}
	}
	if (sl->count_p != 1 || sl->count_e != 1)
		display_error(4);
	if (sl->count_c < 1)
		display_error(5);
}

void	check_walls(char **map, int size)
{
	int	i;
	int	len;

	i = -1;
	if (size > 0)
	{
		while (map[size - 1][++i])
		{
			if (map[size - 1][i] != '1')
				display_error(2);
		}
		size--;
	}
	i = -1;
	while (size > 1)
	{
		len = ft_strlen(map[size]);
		if (map[size - 1][0] != '1' || map[size - 1][len - 1] != '1')
			display_error(2);
		size--;
	}
	if (size == 1)
		check_walls(map, size);
}
