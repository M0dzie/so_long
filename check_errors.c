/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:23 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/13 18:48:24 by thmeyer          ###   ########.fr       */
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

void	elements_count(t_map **map, int size)
{
	int	i;

	while (size > 0)
	{
		i = -1;
		while ((*map)->mapping[size - 1][++i])
		{
			if ((*map)->mapping[size - 1][i] == 'C')
				(*map)->count_c++;
			else if ((*map)->mapping[size - 1][i] == 'P')
			{
				(*map)->count_p++;
				(*map)->x = i;
				(*map)->y = size - 1;
			}
			else if ((*map)->mapping[size - 1][i] == 'E')
				(*map)->count_e++;
		}
		size--;
	}
	if ((*map)->count_p != 1 || (*map)->count_e != 1)
		display_error(4);
	if ((*map)->count_c < 1)
		display_error(5);
}

void	check_walls(char **mapping, int size)
{
	int	i;
	int	len;

	i = 0;
	if (size > 0)
	{
		while (mapping[size - 1][i])
		{
			if (mapping[size - 1][i] != '1')
				display_error(2);
			i++;
		}
		size--;
	}
	while (size > 1)
	{
		len = ft_strlen(mapping[size]);
		if (mapping[size - 1][0] != '1' || mapping[size - 1][len - 1] != '1')
			display_error(2);
		size--;
	}
	if (size == 1)
		check_walls(mapping, size);
}
