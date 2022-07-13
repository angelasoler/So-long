/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:50:18 by asoler            #+#    #+#             */
/*   Updated: 2022/07/13 19:05:55 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_assets(t_images *assets, void *init)
{
	assets->wall = mlx_xpm_file_to_image \
	(init, WALL_PATH, &assets->height, &assets->width);
	assets->back_ground = mlx_xpm_file_to_image \
	(init, BACKGROUND_PATH, &assets->height, &assets->width);
	assets->collectibles = mlx_xpm_file_to_image \
	(init, COLLECTIBLES_PATH, &assets->height, &assets->width);
	assets->exit = mlx_xpm_file_to_image \
	(init, EXIT_PATH, &assets->height, &assets->width);
	assets->player = mlx_xpm_file_to_image \
	(init, PLAYER_PATH, &assets->height, &assets->width);
}

void	put_image_into_screen(t_mlx *mlx, char map_composing, t_images assets)
{
	if (map_composing == '1')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.wall, assets.x, assets.y);
	else if (map_composing == '0')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.back_ground, assets.x, assets.y);
	else if (map_composing == 'C')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.collectibles, assets.x, assets.y);
	else if (map_composing == 'E')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.exit, assets.x, assets.y);
	else if (map_composing == 'P')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.player, assets.x, assets.y);
}

int	close_window(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx_destroy_image(mlx->init, mlx->assets.wall);
	mlx_destroy_image(mlx->init, mlx->assets.back_ground);
	mlx_destroy_image(mlx->init, mlx->assets.collectibles);
	mlx_destroy_image(mlx->init, mlx->assets.exit);
	mlx_destroy_image(mlx->init, mlx->assets.player);
	while (mlx->read_map.map[i])
	{
		free(mlx->read_map.map[i]);
		i++;
	}
	free(mlx->read_map.map);
	mlx_destroy_window(mlx->init, mlx->window);
	mlx_destroy_display(mlx->init);
	free(mlx->init);
	exit (0);
}

int	key_input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		close_window(mlx);
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
		move_player(mlx, mlx->assets.p_position.x, \
		mlx->assets.p_position.y, key);
	return (0);
}

int	no_event_loop(t_mlx *mlx)
{
	mlx->joker = 0;
	return (0);
}
