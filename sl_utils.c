/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:55 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/11 14:52:37 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	sl_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

t_map	*map_new(char **map)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		exit(0);
	if (new)
	{
		new->mapping = map;
		new->count_c = 0;
		new->count_p = 0;
		new->count_e = 0;
		new->next = 0;
	}
	return (new);
}

// void	map_add_back(t_map **map, t_map *new)
// {
// 	t_map	*last_line;

// 	if (!(*map))
// 		(*map) = new;
// 	else
// 	{
// 		last_line = map_last((*map));
// 		last_line->next = new;
// 	}
// }

// t_map	*map_last(t_map *map)
// {
// 	t_map	*last_line;

// 	if (!map)
// 		return (0);
// 	while (map)
// 	{
// 		last_line = map;
// 		map = map->next;
// 	}
// 	return (last_line);
// }