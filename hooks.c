/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:29:03 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/16 16:53:45 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_keycode(int keycode, t_long **sl)
{
	if (keycode == 53)
		exit_win(sl);
	else
		move_char(keycode, sl);
	ft_printf("keycode : %d\n", keycode);
	return (0);
}

int	exit_win(t_long **sl)
{
	mlx_destroy_window((*sl)->mlx_ptr, (*sl)->mlx_win);
	//free_struct
	exit(0);
}

int	move_char(int keycode, t_long **sl)
{
	mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, (*sl)->bush.img, \
	(*sl)->y * 32, (*sl)->x * 32);
	ft_printf("y : %d\n", (*sl)->y);
	if (keycode == 13 && (*sl)->map[(*sl)->y - 1][(*sl)->x] != '1')
	{
		mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
		(*sl)->up.img, (*sl)->y - 1 * 32, (*sl)->x * 32);
		(*sl)->y -= 1;
	}
	(*sl)->count_m += 1;
	ft_printf("count_m : %d\n", (*sl)->count_m);
	ft_printf("y : %d\n", (*sl)->y);
	// if (keycode == 12)
	// 	mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
	// 	start.img, (*sl)->y - 1 * 32, (*sl)->x * 32);
	// if (keycode == 12)
	// 	mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
	// 	start.img, (*sl)->y - 1 * 32, (*sl)->x * 32);
	// if (keycode == 12)
	// 	mlx_put_image_to_window((*sl)->mlx_ptr, (*sl)->mlx_win, \
	// 	start.img, (*sl)->y - 1 * 32, (*sl)->x * 32);
	return (0);
}
