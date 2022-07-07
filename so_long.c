/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:05 by asoler            #+#    #+#             */
/*   Updated: 2022/07/07 15:44:28 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprites(int fd, t_mlx mlx)
{
	char		*line;
	int			i;
	t_images	assets;

	line = malloc(sizeof(char) * 1);
	*line = 0;
	assets.y = 0;
	allocate_assets(&assets, mlx.init);
	line = get_next_line(fd);
	while (line)
	{
		assets.x = 0;
		i = 0;
		while (line[i] != '\n')
		{
			put_image_into_screen(mlx, line[i], assets);
			i++;
			assets.x += 32;
		}
		assets.y += 32;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	open_window(t_map *read_map)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, read_map->x, \
	read_map->y, "FT Ninja Frog, So Long");
	put_sprites(read_map->fd, mlx);
	mlx_loop(mlx.init);
}

int	get_map_size(t_map *read_map)
{
	char	*line;
	int		height;

	line = malloc(sizeof(char) * 1);
	*line = 0;
	height = 0;
	while (line)
	{
		free(line);
		line = get_next_line(read_map->fd);
		if (!line)
			break ;
		read_map->x = (int)ft_strlen(line) - 1;
		//function if height 0 verify all is 1
		//and all first and last is 1 on other lines
		height++;
	}
	//same function that verify all lines is just 1
	read_map->x *= 32;
	read_map->y = height * 32;
	//error if *x == *y
	//map must be rectangular?
	free(line);
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
	read_map.fd = open(argv[1], O_RDONLY);
	open_window(&read_map);
	return (0);
}

// If any misconfiguration of any kind is encountered in the file,
// the program must exit in a clean way, and return "Error\n" followed
// by an explicit error message of your choice.