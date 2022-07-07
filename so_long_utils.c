/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:50:18 by asoler            #+#    #+#             */
/*   Updated: 2022/07/07 15:42:41 by asoler           ###   ########.fr       */
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

void	put_image_into_screen(t_mlx mlx, char map_composing, t_images assets)
{
	if (map_composing == '1')
		mlx_put_image_to_window \
	(mlx.init, mlx.window, assets.wall, assets.x, assets.y);
	else if (map_composing == '0')
		mlx_put_image_to_window \
	(mlx.init, mlx.window, assets.back_ground, assets.x, assets.y);
	else if (map_composing == 'C')
		mlx_put_image_to_window \
	(mlx.init, mlx.window, assets.collectibles, assets.x, assets.y);
	else if (map_composing == 'E')
		mlx_put_image_to_window \
	(mlx.init, mlx.window, assets.exit, assets.x, assets.y);
	else if (map_composing == 'P')
		mlx_put_image_to_window \
	(mlx.init, mlx.window, assets.player, assets.x, assets.y);
}

//TODO
// - see if window is ereasing when moving
// - see how to make transparency for player and collectibles
// - make error function
//		* verify map
//				- has all wall entire
//				- has almost one of each asset beside the walls
//		* if fd != 3 -> or == -1
// - close window events: clicking and with esc
// - move player
//		*player eats a collectable, -> erase collectible
//		*when its in front exit over program 
			// -> but just when there's no more collectibles