/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:05 by asoler            #+#    #+#             */
/*   Updated: 2022/07/12 16:51:25 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_images	put_sprites(t_mlx *mlx)
{
	int			v;
	int			i;
	int			height;

	allocate_assets(&mlx->assets, mlx->init);
	height = mlx->read_map.y / 32;
	mlx->assets.y = 0;
	v = 0;
	while (v < height)
	{
		mlx->assets.x = 0;
		i = 0;
		while (mlx->read_map.map[v][i])
		{
			put_image_into_screen(mlx, mlx->read_map.map[v][i], mlx->assets);
			mlx->assets.x += 32;
			i++;
		}
		mlx->assets.y += 32;
		v++;
	}
	return (mlx->assets);
}

void	open_window(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, mlx->read_map.x, \
	mlx->read_map.y, "FT Ninja Frog, So Long");
	put_sprites(mlx);
	mlx_loop_hook(mlx->init, &no_event_loop, mlx);
	mlx_key_hook(mlx->window, &key_hook, mlx);
	mlx_hook(mlx->window, 17, 0, &close_window, mlx);
	mlx_loop(mlx->init);
}

int	get_map_size(t_map *read_map)
{
	char	*line;
	char	*map;
	int		height;

	if (read_map->fd == -1)
		return (1);
	line = get_next_line(read_map->fd);
	map = malloc(sizeof(char) * 1);
	*map = 0;
	height = 0;
	while (line)
	{
		read_map->x = (int)ft_strlen(line) - 1;
		map = ft_strjoin(map, line);
		//function if height 0 verify all is 1
		//and all first and last is 1 on other lines
		height++;
		free(line);
		line = get_next_line(read_map->fd);
	}
	read_map->map = ft_split(map, '\n');
	//same function that verify all lines is just 1
	//verify if is a valid map -> has one of each assets kind
	read_map->x *= 32;
	read_map->y = height * 32;
	//error if *x == *y
	//map must be rectangular?
	free(line);
	free(map);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		error;

	ft_printf("%d\n", argc);
	mlx.read_map.fd = open(argv[1], O_RDONLY);
	error = get_map_size(&mlx.read_map);
	close(mlx.read_map.fd);
	if (error)
		exit(0);
	open_window(&mlx);
	return (0);
}

//TODO verify error in arguments

// If any misconfiguration of any kind is encountered in the file,
// the program must exit in a clean way, and return "Error\n" followed
// by an explicit error message of your choice.