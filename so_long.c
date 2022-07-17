/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:05 by asoler            #+#    #+#             */
/*   Updated: 2022/07/17 17:32:16 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_sprites(t_mlx *mlx)
{
	int	line;
	int	row;

	mlx->assets.y = 0;
	line = 0;
	while (line < mlx->read_map.height)
	{
		mlx->assets.x = 0;
		row= 0; 
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
	return (0);
}

void	open_window(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, mlx->read_map.x, \
	mlx->read_map.y, "FT Ninja Frog, So Long");
	allocate_assets(&mlx->assets, mlx->init);
	put_sprites(mlx);
	mlx_key_hook(mlx->window, &key_input, mlx);
	mlx_loop_hook(mlx->init, &put_sprites, mlx);
	mlx_hook(mlx->window, 17, 0, &close_window, mlx);
	mlx_loop(mlx->init);
}

int	get_map_size(t_map *read_map)
{
	int		error_verify;

	read_map->str_map = ft_calloc(1, sizeof(char));
	read_map->line = get_next_line(read_map->fd);
	read_map->x = ft_strlen(read_map->line) - 1;
	while (read_map->line)
	{
		read_map->str_map = ft_strjoin(read_map->str_map, read_map->line);
		free(read_map->line);
		read_map->line = get_next_line(read_map->fd);
	}
	read_map->map = ft_split(read_map->str_map, '\n');
	read_map->height = get_map_height(read_map->map);
	error_verify = verify_map(read_map);
	read_map->x *= 32;
	read_map->y = read_map->height * 32;
	free(read_map->line);
	free(read_map->str_map);
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
	{
		ft_printf("Error\n%s\n", strerror(errno));
		close(mlx.read_map.fd);
		exit(0);
	}
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
