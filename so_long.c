/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:05 by asoler            #+#    #+#             */
/*   Updated: 2022/07/06 14:19:21 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprites(int fd, char *init, char *window)
{
	char		*line;
	int			i;
	// int			images.x;
	// int			images.y;
	t_images	images;

	*line = 0;
	images.x = 0;
	images.y = 0;
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		while (line[i] != '\0')
		{
			if (line[i] == '1')
				images.image = mlx_xpm_file_to_image(init, WALL_PATH, &images.x, &images.y);
			else if (line[i] == '0')
				images.image = mlx_xpm_file_to_image(init, BACKGROUND_PATH, &images.x, &images.y);
			else if (line[i] == 'C')
				images.image = mlx_xpm_file_to_image(init, COLLECTIBLES_PATH, &images.x, &images.y);
			else if (line[i] == 'E')
				images.image = mlx_xpm_file_to_image(init, EXIT_PATH, &images.x, &images.y);
			else if (line[i] == 'P')
				images.image = mlx_xpm_file_to_image(init, PLAYER_PATH, &images.x, &images.y);
			i++;
			images.x += 32;
		}
		images.y += 32;
	}
	close(fd);
	free(line);
}

void	open_window(int *x, int *y, int fd)
{
	t_mlx mlx;

	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, *x, *y, "FT Ninja Frog, So Long");
	put_sprites(fd, mlx.init, mlx.window);
	mlx_loop(mlx.init);
}

int	get_map_size(t_map *read_map)
{
	//TODOverify errors
	char	*line;
	int		height;

	line = malloc(sizeof(char) * 1);
	*line = 0;
	while (line)
	{
		free(line);
		line = get_next_line(read_map->fd);
		*read_map->x =(int)ft_strlen(line) * 32;
		//function if height 0 verify all is 1
		//and all first and last is 1 on other lines
		height++;
	}
	//same function that verify all lines is just 1
	*read_map->y = height * 32;
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
	ft_printf("%d\n", read_map.fd);
	error = get_map_size(&read_map);
	close(read_map.fd);
	//verify error
	if (error)
		exit(1);
	read_map.fd = open(argv[1], O_RDONLY);
	open_window(read_map.x, read_map.y, read_map.fd);
	return (0);
}

// If any misconfiguration of any kind is encountered in the file, the program must
// exit in a clean way, and return "Error\n" followed by an explicit error message of
// your choice.
