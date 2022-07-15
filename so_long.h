/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:04:34 by asoler            #+#    #+#             */
/*   Updated: 2022/07/16 01:20:36 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include <mlx.h>
# include <X11/keysym.h>
# include "includes/get_next_line.h"
# include "includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# define SO_LONG_H
# define PLAYER_PATH "images/ninja_frog.xpm"
# define WALL_PATH "images/wall_brick.xpm"
# define COLLECT_PATH "images/raspberry_pie.xpm"
# define EXIT_PATH "images/door.xpm"
# define BCKGRND_PATH "images/wood_background.xpm"

typedef struct s_map_characters
{
	int	c;
	int	p;
	int	e;
	int	zero;
}	t_map_characters;

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct s_images
{
	void		*wall;
	void		*bck_grnd;
	void		*collect;
	void		*exit;
	void		*player;
	int			x;
	int			y;
	t_position	p_position;
}	t_images;

typedef struct s_map
{
	char	**map;
	int		fd;
	int		height;
	int		x;
	int		y;
}	t_map;

typedef struct s_mlx
{
	void		*init;
	void		*window;
	int			joker;
	t_images	assets;
	t_map		read_map;
}	t_mlx;

void	allocate_assets(t_images *assets, void *init);
void	put_image_into_screen(t_mlx *mlx, char map_composing, t_images assets);
void	move_player(t_mlx *mlx, int x, int y, int key);
int		key_input(int key, t_mlx *mlx);
int		close_window(t_mlx *mlx);
int		no_event_loop(t_mlx *mlx);
void	put_sprites(t_mlx *mlx);
int		verify_map_file_type(char *map_argument);
void	free_map(char **map);
int		verify_map(t_map *read_map);

#endif