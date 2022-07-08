/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:05 by asoler            #+#    #+#             */
/*   Updated: 2022/07/08 20:44:26 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprites(t_map read_map, t_mlx mlx)
{
	char		*line;
	int			v;
	int			i;
	int			height;
	t_images	assets;

	allocate_assets(&assets, mlx.init);
	height = read_map.y / 32;
	assets.y = 0;
	v = 0;
	while (v < height)
	{
		assets.x = 0;
		i = 0;
		while (read_map.map[v][i])
		{
			put_image_into_screen(mlx, read_map.map[v][i], assets);
			assets.x += 32;
			i++;
		}
		assets.y += 32;
		v++;
	}
}

void	open_window(t_map *read_map)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, read_map->x, \
	read_map->y, "FT Ninja Frog, So Long");
	put_sprites(*read_map, mlx);
	mlx_loop(mlx.init);
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
	t_map	read_map;
	int		error;

	//TODO verify error in arguments
	//if path exist
	//if is a valid map -> has one of each assets kind
	read_map.fd = open(argv[1], O_RDONLY);
	error = get_map_size(&read_map);
	close(read_map.fd);
	//verify error
	if (error)
		exit(1);
	open_window(&read_map);
	return (0);
}

// If any misconfiguration of any kind is encountered in the file,
// the program must exit in a clean way, and return "Error\n" followed
// by an explicit error message of your choice.