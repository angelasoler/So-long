/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:04:34 by asoler            #+#    #+#             */
/*   Updated: 2022/07/06 02:51:18 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include <mlx.h>
# include "includes/get_next_line.h"
# include "includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# define SO_LONG_H
# define PLAYER_PATH "../images/Ninja_Frog.xpm"
# define WALL_PATH "../images/DUNGEONBRICKS.xpm"
# define COLLECTIBLES_PATH "../images/apple_pie.xpm"
# define EXIT_PATH "../images/OFFICEDOOR.xpm"
# define BACKGROUND_PATH "../images/RUNKS.xpm"

typedef struct s_mlx
{
	void	*init;
	void	*window;
	void	*image;
	int		windowdow_width;
	int		window_height;
}	t_mlx;

typedef struct s_images
{
	void	*image;
	int			*x;
	int			*y;
}	t_images;

typedef struct s_map
{
	int			fd;
	int			*x;
	int			*y;
}	t_map;

// size_t	ft_strlen(const char *str);
// char	*get_next_line(int fd);

#endif