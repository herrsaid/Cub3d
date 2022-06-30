#include "../inc/main.h"

int	des_b(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
}

void	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
}

void drawPlayer(void *mlx, void *win, float px, float py)
{
    mlx_string_put(mlx,
		win, px, py, 255, "<-(:)->");
	//mlx_pixel_put (mlx, win, px, py, 255);
}