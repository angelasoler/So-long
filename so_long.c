/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:05 by asoler            #+#    #+#             */
/*   Updated: 2022/07/06 02:51:39 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprites(int fd, char *init, char *window)
{
	char		*line;
	int			i;
	int			x_position;
	int			y_position;
	t_images	images;

	*line = 0;
	x_position = 0;
	y_position = 0;
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		while (line[i] != '\0')
		{
			if (line[i] == '1')
				images.image = mlx_xpm_file_to_image(init, WALL_PATH, images.x, images.y);
			else if (line[i] == '0')
				images.image = mlx_xpm_file_to_image(init, BACKGROUND_PATH, images.x, images.y);
			else if (line[i] == 'C')
				images.image = mlx_xpm_file_to_image(init, COLLECTIBLES_PATH, images.x, images.y);
			else if (line[i] == 'E')
				images.image = mlx_xpm_file_to_image(init, EXIT_PATH, images.x, images.y);
			else if (line[i] == 'P')
				images.image = mlx_xpm_file_to_image(init, PLAYER_PATH, images.x, images.y);
			i++;
			x_position += 32;
		}
		y_position += 32;
	}
}

void	open_window(int *x, int *y, int fd)
{
	t_mlx mlx;

	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, *x, *y, "FT Ninja Frog, So Long");
	put_sprites(fd, mlx.init, mlx.window);
	mlx_loop(mlx.init);
}

int	get_map_size(int *x, int *y, int fd)
{
	//TODOverify errors
	char	*line;
	int		height;

	*line = 0;
	while (line)
	{
		line = get_next_line(fd);
		*x = ft_strlen(line) * 32;
		//function if height 0 verify all is 1
		//and all first and last is 1 on other lines
		free(line);
		height++;
	}
	//same function that verify all lines is just 1
	*y = height * 32;
	//error if *x == *y
	//map must be rectangular?
	free(line);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	first_read;
	int		error;

	//TODO verify error in arguments
	//if path exist
	//if is a valid map -> has one of each assets kind
	first_read.fd = open(argv[1], O_RDONLY);
	error = get_map_size(first_read.x, first_read.y, first_read.fd);
	close(first_read.fd);
	//verify error
	if (error)
		exit(1);
	first_read.fd = open(argv[1], O_RDONLY);
	open_window(first_read.x, first_read.y, first_read.fd);
	return (0);
}

// If any misconfiguration of any kind is encountered in the file, the program must
// exit in a clean way, and return "Error\n" followed by an explicit error message of
// your choice.
