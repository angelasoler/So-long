#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>


# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*relative_path = "../images/DUNGEONBRICKS.xpm";
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 448, 160, "My first window!");
	img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img_width, &img_height);
	printf("%p\n", img);
	while (x <= 600 && y <= 300)
	{
		while (x < 600)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y);
			x += 30;
		}
		if (y < 300)
		{
			x = 0;
			y += 30;
		}
	}
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img, 30, 0);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img, 500, 100);
	mlx_loop(mlx_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// mlx_destroy_display(mlx_ptr);
	// free(mlx_ptr);
}
