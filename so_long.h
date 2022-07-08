/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:04:34 by asoler            #+#    #+#             */
/*   Updated: 2022/07/08 19:55:34 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include <mlx.h>
# include "includes/get_next_line.h"
# include "includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# define SO_LONG_H
# define PLAYER_PATH "images/ninja_frog.xpm"
# define WALL_PATH "images/wall_brick.xpm"
# define COLLECTIBLES_PATH "images/raspberry_pie.xpm"
# define EXIT_PATH "images/door.xpm"
# define BACKGROUND_PATH "images/wood_background.xpm"

typedef struct s_mlx
{
	void	*init;
	void	*window;
	void	*image;
	int		windowd_width;
	int		window_height;
}	t_mlx;

// typedef struct s_asset
// {
// 	void	*asset;
// 	int		x;
// 	int		y;
// 	s_asset	*next;
// }	t_asset;

typedef struct s_images
{
	void	*wall;
	void	*back_ground;
	void	*collectibles;
	void	*exit;
	void	*player;
	int		x;
	int		y;
	int		height;
	int		width;
	// t_asset	image;
}	t_images;

typedef struct s_map
{
	char	**map;
	int		fd;
	int		x;
	int		y;
}	t_map;

// int	so_long(int argc, char *argv[]);
//TODO verify why make is just accepting main function

void	allocate_assets(t_images *assets, void *init);
void	put_image_into_screen(t_mlx mlx, char map_composing, t_images assets);

#endif