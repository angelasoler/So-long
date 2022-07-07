/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:05 by asoler            #+#    #+#             */
/*   Updated: 2022/07/07 00:38:12 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprites(int fd, t_mlx *mlx)
{
	char		*line;
	int			i;
	t_images	assets;
	char	*relative_path = "images/DUNGEONBRICKS.xpm";


	line = malloc(sizeof(char) * 1);
	*line = 0;
	assets.y = 0;
	//TODO create function and struct for allocated assets
	//t_assets	allocated_assets(void); -> prototype like these?
	assets.wall = mlx_xpm_file_to_image(mlx->init, WALL_PATH, &assets.height, &assets.width);
	assets.back_ground = mlx_xpm_file_to_image(mlx->init, BACKGROUND_PATH, &assets.height, &assets.width);
	assets.collectibles = mlx_xpm_file_to_image(mlx->init, COLLECTIBLES_PATH, &assets.height, &assets.width);
	assets.exit = mlx_xpm_file_to_image(mlx->init, EXIT_PATH, &assets.height, &assets.width);
	assets.player = mlx_xpm_file_to_image(mlx->init, PLAYER_PATH, &assets.height, &assets.width);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break;
		assets.x = 0;
		i = 0;
		while (line[i] != '\n')
		{
			//TODO create function with these verifications
			if (line[i] == '1')
				mlx_put_image_to_window(mlx->init, mlx->window, assets.wall, assets.x, assets.y);
			else if (line[i] == '0')
				mlx_put_image_to_window(mlx->init, mlx->window, assets.back_ground, assets.x, assets.y);
			else if (line[i] == 'C')
				mlx_put_image_to_window(mlx->init, mlx->window, assets.collectibles, assets.x, assets.y);
			else if (line[i] == 'E')
				mlx_put_image_to_window(mlx->init, mlx->window, assets.exit, assets.x, assets.y);
			else if (line[i] == 'P')
				mlx_put_image_to_window(mlx->init, mlx->window, assets.player, assets.x, assets.y);
			i++;
			assets.x += 32;
		}
		assets.y += 32;
	}
	close(fd);
	free(line);
}

void	open_window(t_map *read_map)
{
	t_mlx mlx;


	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, read_map->x, read_map->y, "FT Ninja Frog, So Long");
	put_sprites(read_map->fd, &mlx);
	mlx_loop(mlx.init);
}

int	get_map_size(t_map *read_map)
{
	//TODOverify errors
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
			break;
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

// If any misconfiguration of any kind is encountered in the file, the program must
// exit in a clean way, and return "Error\n" followed by an explicit error message of
// your choice.
