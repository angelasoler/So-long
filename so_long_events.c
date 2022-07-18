/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:44:35 by asoler            #+#    #+#             */
/*   Updated: 2022/07/18 02:28:39 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_into_exit_door(t_mlx *mlx, int x, int y)
{
	int	i;

	i = 0;
	while (mlx->read_map.map[i])
	{
		if (mlx->read_map.map[y][x] != 'E' || \
		ft_strchr(mlx->read_map.map[i], 'C'))
			return ;
		i++;
	}
	ft_printf("%s\n", "Yeah dude! End of game, so long!");
	close_window(mlx);
}

void	move_player(t_mlx *mlx, int x, int y, int key)
{
	t_position	next;
	static int	moves;

	next.x = x;
	next.y = y;
	if (key == XK_w || key == XK_Up)
		next.y--;
	else if (key == XK_a || key == XK_Left)
		next.x--;
	else if (key == XK_d || key == XK_Right)
		next.x++;
	else if (key == XK_s || key == XK_Down)
		next.y++;
	get_into_exit_door(mlx, next.x, next.y);
	if (mlx->read_map.map[next.y][next.x] == '0' || \
	mlx->read_map.map[next.y][next.x] == 'C')
	{
		mlx_clear_window(mlx->init, mlx->window);
		mlx->read_map.map[y][x] = '0';
		mlx->read_map.map[next.y][next.x] = 'P';
		put_sprites(mlx);
		moves++;
		ft_printf("Move Counter: %d\n", moves);
	}
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
