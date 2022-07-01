#include "../inc/cub3d.h"

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

void	check_file(char *str)
{
	if (ft_strcmp(&str[ft_strlen(str) - 4], ".cub") != 0)
	{
		perror("extention error\n");
		exit(1);
	}
}

void	init_file(t_file *file, char *filename)
{
	file = (t_file *)malloc(sizeof(t_file));
	file->file_line = 0;
	file->file_name = filename;
}