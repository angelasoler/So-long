/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:04:19 by asoler            #+#    #+#             */
/*   Updated: 2022/07/05 12:47:43 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_loop(mlx_ptr);
}

