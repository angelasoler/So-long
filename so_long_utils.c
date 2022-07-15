/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:50:18 by asoler            #+#    #+#             */
/*   Updated: 2022/07/15 17:58:55 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_assets(t_images *assets, void *init)
{
	int	x;
	int	y;

	assets->wall = mlx_xpm_file_to_image(init, WALL_PATH, &x, &y);
	assets->bck_grnd = mlx_xpm_file_to_image(init, BCKGRND_PATH, &x, &y);
	assets->collect = mlx_xpm_file_to_image(init, COLLECT_PATH, &x, &y);
	assets->exit = mlx_xpm_file_to_image(init, EXIT_PATH, &x, &y);
	assets->player = mlx_xpm_file_to_image(init, PLAYER_PATH, &x, &y);
}

void	put_image_into_screen(t_mlx *mlx, char map_composing, t_images assets)
{
	if (map_composing == '1')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.wall, assets.x, assets.y);
	else if (map_composing == '0')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.bck_grnd, assets.x, assets.y);
	else if (map_composing == 'C')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.collect, assets.x, assets.y);
	else if (map_composing == 'E')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.exit, assets.x, assets.y);
	else if (map_composing == 'P')
		mlx_put_image_to_window \
	(mlx->init, mlx->window, assets.player, assets.x, assets.y);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->init, mlx->assets.wall);
	mlx_destroy_image(mlx->init, mlx->assets.bck_grnd);
	mlx_destroy_image(mlx->init, mlx->assets.collect);
	mlx_destroy_image(mlx->init, mlx->assets.exit);
	mlx_destroy_image(mlx->init, mlx->assets.player);
	free_map(mlx->read_map.map);
	mlx_destroy_window(mlx->init, mlx->window);
	mlx_destroy_display(mlx->init);
	free(mlx->init);
	exit (0);
}

int	key_input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		close_window(mlx);
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d || \
	key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left)
		move_player(mlx, mlx->assets.p_position.x, \
		mlx->assets.p_position.y, key);
	return (0);
}

int	no_event_loop(t_mlx *mlx)
{
	mlx->joker = 0;
	return (0);
}
