#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_data;

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	printf("Keyrelease: %p\n", data);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		// mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		// exit(0);
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	printf("Keyrelease: %p\n", data);
	return (0);
}

int	main(void)
{
	t_data data;
	// void	*mlx_ptr;
	// void	*win_ptr;
	// void	*img;
	// char	*relative_path = "../images/ninja_frog.xpm";
	// int		img_width;
	// int		img_height;
	// int		x;
	// int		y;

	// x = 0;
	// y = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 448, 160, "My first window!");
	// img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height);
	// // printf("%p\n", img);
	// while (x <= 600 && y <= 300)
	// {
	// 	while (x < 600)
	// 	{
	// 		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, x, y);
	// 		x += 30;
	// 	}
	// 	if (y < 300)
	// 	{
	// 		x = 0;
	// 		y += 30;
	// 	}
	// }
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 0, 0);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 30, 0);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 500, 100);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_keypress, &data);
	// mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	// mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
}
