/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:44:35 by asoler            #+#    #+#             */
/*   Updated: 2022/07/13 13:27:04 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_mlx *mlx, int x, int y, int key)
{
	t_position next;

	next.x = x;
	next.y = y;
	if (key == XK_w)
		next.y--;
	else if (key == XK_a)
		next.x--;
	else if (key == XK_d)
		next.x++;
	else if (key == XK_s)
		next.y++;
	if (mlx->read_map.map[next.y][next.x] == '0' || mlx->read_map.map[next.y][next.x] == 'C')
	{
		mlx_clear_window(mlx->init, mlx->window);
		mlx->read_map.map[y][x] = '0';
		mlx->read_map.map[next.y][next.x] = 'P';
		put_sprites(mlx);
	}
}
