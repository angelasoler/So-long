/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:44:35 by asoler            #+#    #+#             */
/*   Updated: 2022/07/14 03:09:05 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_mlx *mlx, int x, int y, int key)
{
	t_position	next;
	static int	moves;

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

// int	error_verify(char **map)
// {
// 	int	i;

// 	while(map[i])
// 	{
// 		i++;
// 	}
// }

int	verify_map_file_type(char *map_argument)
{
	size_t	len;
	char	*type;

	len = ft_strlen(map_argument);
	type = ft_strnstr(map_argument, ".ber", len);
	if (!type)
		return (1);
	else if (*(type + 4) != '\0')
		return (1);
	return (0);
}

// TODO
// - permit player get into exit and finish game
// - read also arrow keys
// - redraw screen after window or whatever overlap game
		// => see expose a hook_loop functions doc