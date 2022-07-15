/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:44:35 by asoler            #+#    #+#             */
/*   Updated: 2022/07/16 01:37:09 by asoler           ###   ########.fr       */
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

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	different_characters(char *line)
{
	// ft_printf("%s\n", line);
	while (*line)
	{
		if (*line != 'C' && *line != 'E' && *line != 'P' && \
		*line != '0' && *line != '1')
			return (1);
		line++;
	}
	return (0);
}

int	wall_sorrounded(t_map *read_map)
{
	int	x;
	int	y;
	int	y_backup;
	int	x_backup;

	x = read_map->x - 1;
	y = read_map->height - 1;
	x_backup = x;
	y_backup = y;
	// ft_printf("x = %d\n y = %d\n", x, y);
	while (y_backup >= 0)
	{
		if (read_map->map[y_backup][0] != '1' || \
		read_map->map[y_backup][x_backup] != '1')
			return (1);
		y_backup--;
	}
	while (x >= 0)
	{
		if (read_map->map[0][x] != '1' || read_map->map[y][x] != '1')
			return (1);
		x--;
	}
	return (0);
}

int	verify_map(t_map *read_map)
{
	t_map_characters	characters;
	int					i;


	i = 0;
	characters.c = 0;
	characters.p = 0;
	characters.e = 0;
	characters.zero = 0;
	while (read_map->map[i])
	{
		if ((ft_strlen(read_map->map[i]) != (size_t)read_map->x) || \
		different_characters(read_map->map[i]) || wall_sorrounded(read_map))
			return (1);
		if (ft_strchr(read_map->map[i], 'C'))
			characters.c++;
		if (ft_strchr(read_map->map[i], '0'))
			characters.zero++;
		if (ft_strchr(read_map->map[i], 'P'))
			characters.p++;
		if (ft_strchr(read_map->map[i], 'E'))
			characters.e++;
		i++;
	}
	if (characters.c == 0 || characters.e != 1 || characters.p != 1 || characters.zero == 0)
		return (1);
	return (0);
}

int	verify_map_file_type(char *map_argument)
{
	size_t	len;
	char	*type;

	len = ft_strlen(map_argument);
	type = ft_strnstr(map_argument, ".ber", len);
	if (!type || (*(type + 4) != '\0'))
		return (1);
	return (0);
}

// TODO
// - permit player get into exit and finish game
// - read also arrow keys
// - redraw screen after window or whatever overlap game
		// => see expose a hook_loop functions doc