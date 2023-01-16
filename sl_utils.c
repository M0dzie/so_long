/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:55 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/16 14:27:37 by thmeyer          ###   ########.fr       */
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
	exit (0);
}

size_t	sl_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

t_long	*map_new(char **map)
{
	t_long	*new;

	new = malloc(sizeof(t_long));
	if (!new)
		exit(0);
	if (new)
	{
		new->map = map;
		new->count_c = 0;
		new->count_p = 0;
		new->count_e = 0;
		new->count_m = 0;
		new->next = 0;
	}
	return (new);
}
