/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:55 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/18 11:47:52 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_error(int type)
{
	ft_putendl_fd("Error", 2);
	if (type == 1)
		ft_putendl_fd("The map must be rectangular.", 2);
	if (type == 2)
		ft_putendl_fd("The map is not surrounded by walls.", 2);
	if (type == 3)
		ft_putendl_fd("No valid path in the map.", 2);
	if (type == 4)
		ft_putendl_fd("The map must contain 1 exit and 1 start.", 2);
	if (type == 5)
		ft_putendl_fd("The map must contain at least 1 collectible.", 2);
	if (type == 6)
		ft_putendl_fd("The program take only 1 map as parameter.", 2);
	if (type == 7)
		ft_putendl_fd("The map is not valid.", 2);
	if (type == 8)
		ft_putendl_fd("No such file or directory.", 2);
	if (type == 9)
		ft_putendl_fd("The map is empty.", 2);
	if (type == 10)
		ft_putendl_fd("The map must contain only 0, 1, C, P, or E char.", 2);
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
	new->map = map;
	new->count_c = 0;
	new->count_p = 0;
	new->count_e = 0;
	new->count_m = 0;
	new->current_c = 0;
	new->x = 0;
	new->y = 0;
	new->status = 0;
	return (new);
}
