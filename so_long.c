/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:05 by asoler            #+#    #+#             */
/*   Updated: 2022/07/06 16:21:55 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	put_sprites(int fd, t_mlx *mlx)
// {
// 	char		*line;
// 	int			i;
// 	t_images	images;


// 	line = malloc(sizeof(char) * 1);
// 	*line = 0;
// 	images.x = 0;
// 	images.y = 0;
// 	i = 0;
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		if (!line)
// 			break;
// 		while (line[i] != '\0')
// 		{
// 			if (line[i] == '1')
// 				images.image = mlx_xpm_file_to_image(mlx->init, "../images/DUNGEONBRICKS.xpm", &images.height, &images.width);
// 			else if (line[i] == '0')
// 				images.image = mlx_xpm_file_to_image(mlx->init, BACKGROUND_PATH, &images.height, &images.width);
// 			else if (line[i] == 'C')
// 				images.image = mlx_xpm_file_to_image(mlx->init, COLLECTIBLES_PATH, &images.height, &images.width);
// 			else if (line[i] == 'E')
// 				images.image = mlx_xpm_file_to_image(mlx->init, EXIT_PATH, &images.height, &images.width);
// 			else if (line[i] == 'P')
// 				images.image = mlx_xpm_file_to_image(mlx->init, PLAYER_PATH, &images.height, &images.width);

// 			ft_printf("%d\n%d\n%d\n%p\n%p\n%p\n%c\n", images.x, images.y, i, mlx->init, mlx->window, images.image, line[1]);
			
// 			mlx_put_image_to_window(mlx->init, mlx->window, images.image, images.x, images.y);
// 			i++;
// 			images.x += 32;
// 		}
// 		images.y += 32;
// 	}
// 	close(fd);
// 	free(line);
// }

void	open_window(t_map *read_map)
{
	// t_mlx		mlx;
	void	*init;
	void	*window;
	void	*image;
	char	*relative_path = "../images/DUNGEONBRICKS.xpm";
	int		img_width;
	int		img_height;

	ft_printf("%d\n%d\n%d\n", read_map->x, read_map->y, read_map->fd);
	init = mlx_init();
	window = mlx_new_window(init, 448, 160, "FT Ninja Frog, So Long");
	image = mlx_xpm_file_to_image(init, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(init, window, image, 0, 0);
	// put_sprites(read_map->fd, &mlx);
	mlx_loop(init);
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
		read_map->x = (int)ft_strlen(line);
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
