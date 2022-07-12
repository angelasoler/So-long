/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:44:35 by asoler            #+#    #+#             */
/*   Updated: 2022/07/12 21:07:14 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_mlx *mlx, int key)
{
	if (key == XK_w)
	{
		mlx->read_map.map[mlx->assets.player_position.y][mlx->assets.player_position.x] = '0';
		mlx->read_map.map[mlx->assets.player_position.y + 1][mlx->assets.player_position.x] = 'P';
		mlx_clear_window(mlx->init, mlx->window);
		put_sprites(mlx);
	}
}
