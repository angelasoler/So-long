/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:05 by asoler            #+#    #+#             */
/*   Updated: 2022/07/15 18:08:55 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprites(t_mlx *mlx)
{
	int	line;
	int	row;

	mlx->assets.y = 0;
	line = 0;
	while (line < mlx->read_map.height)
	{
		mlx->assets.x = 0;
		row = 0;
		while (mlx->read_map.map[line][row])
		{
			put_image_into_screen(mlx, mlx->read_map.map[line][row], \
			mlx->assets);
			if (mlx->read_map.map[line][row] == 'P')
			{
				mlx->assets.p_position.x = row;
				mlx->assets.p_position.y = line;
			}
			mlx->assets.x += 32;
			row++;
		}
		mlx->assets.y += 32;
		line++;
	}
}

void	open_window(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, mlx->read_map.x, \
	mlx->read_map.y, "FT Ninja Frog, So Long");
	allocate_assets(&mlx->assets, mlx->init);
	put_sprites(mlx);
	mlx_loop_hook(mlx->init, &no_event_loop, mlx);
	mlx_key_hook(mlx->window, &key_input, mlx);
	mlx_hook(mlx->window, 17, 0, &close_window, mlx);
	mlx_loop(mlx->init);
}

int	get_map_size(t_map *read_map)
{
	char	*line;
	char	*map;

	line = get_next_line(read_map->fd);
	map = malloc(sizeof(char) * 1);
	*map = 0;
	read_map->height = 0;
	read_map->x = ft_strlen(line) - 1;
	while (line)
	{
		map = ft_strjoin(map, line);
		read_map->height++;
		free(line);
		line = get_next_line(read_map->fd);
	}
	read_map->map = ft_split(map, '\n');
	read_map->x *= 32;
	read_map->y = read_map->height * 32;
	// error_verify = verify_map(read_map->map);
	free(line);
	free(map);
	if (read_map->x == read_map->y || error_verify)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		error;

	if (argc != 2 || verify_map_file_type(argv[1]))
	{
		ft_printf("Error\n%s\n", strerror(EPERM));
		exit(0);
	}
	mlx.read_map.fd = open(argv[1], O_RDONLY);
	if (mlx.read_map.fd == -1)
		ft_printf("Error\n%s\n", strerror(errno));
	error = get_map_size(&mlx.read_map);
	close(mlx.read_map.fd);
	if (error)
	{
		free_map(mlx.read_map.map);
		ft_printf("Error\n%s\n", strerror(EINVAL));
		exit(0);
	}
	open_window(&mlx);
	return (0);
}

//TODO verify error in arguments
// - file name most end with .ber type
// - map most be rectangular
// - map most be close, surrounded by walls -> 1
// - most have at list one of each -> C,P,E,0
// ** maxamum size?
// 
// If any misconfiguration of any kind is encountered in the (.ber) file,
// the program must exit in a clean way, and return "Error\n" followed
// by an explicit error message of your choice.