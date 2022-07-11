/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:50:18 by asoler            #+#    #+#             */
/*   Updated: 2022/07/11 01:32:59 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

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

int	close_window(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx_clear_window(mlx->init, mlx->window);
	// mlx_loop_end(mlx->init);
	// free(mlx->assets.wall);
	// free(mlx->assets.back_ground);
	// free(mlx->assets.collectibles);
	// free(mlx->assets.exit);
	// free(mlx->assets.player);
	// while(mlx->read_map.map[i])
	// {
	// 	free(mlx->read_map.map[i]);
	// 	i++;
	// }
	free(mlx->read_map.map);
	mlx_destroy_window(mlx->init, mlx->window);
	free(mlx->window);
	return (0);
}


int	key_hook(int key, t_mlx mlx)
{
	ft_printf("%d\n\n\n\n", key);
	if (key == XK_Escape)
	{
		close_window(&mlx);
		exit (0);
	}
	// if (key == 'w')
	// {
	// 	mlx.
	// }
	return (0);
}

// int	cross_mouse_hook(int button, int x, int y, t_mlx mlx)
// {
	
// 	// if (button == 1)
// 	// {
// 	// 	ft_printf("%d\n%d\n", x, y);
// 	// 	ft_printf("%p\n%p\n", mlx.assets.x, mlx.assets.y);
// 	// }
// 	return (0);
// }

//TODO
// - see if window is ereasing when moving
// - see how to make transparency for player and collectibles
// - make error function
//		* verify map
//				- has all wall entire
//				- has almost one of each asset beside the walls
//		* if fd != 3 -> or == -1
// - close window events: clicking closing botton and with esc key
// - move player
//		*player eats a collectable, -> erase collectible
//		*when its in front exit over program 
			// -> but just when there's no more collectibles