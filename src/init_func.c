/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:05:11 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/13 13:14:20 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_game(t_data *data)
{
	data->ccolor = get_color(data->file->config->C);
	data->fcolor = get_color(data->file->config->F);
	data->player = (t_player *)malloc(sizeof(t_player));
	data->ray = (t_ray *)malloc(sizeof(t_ray));
	data->player->pa = degtorad(90);
	if (!ft_check_map(data))
	{
		printf("error in the map file\n");
		exit(1);
	}
	init_images(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, W_W, W_H, "cub3d");
	make_image(data);
	data->image = mlx_new_image(data->mlx, W_W, W_H);
	data->buffer = get_buffer_img(data->image);
	castray(data);
	draw_mini_map(data);
}

void	make_image(t_data *data)
{
	int		y;
	void	*wwimage;
	void	*ewimage;
	void	*swimage;
	void	*nwimage;

	wwimage = mlx_xpm_file_to_image(data->mlx, data->file->config->WE, &y, &y);
	ewimage = mlx_xpm_file_to_image(data->mlx, data->file->config->EA, &y, &y);
	swimage = mlx_xpm_file_to_image(data->mlx, data->file->config->SO, &y, &y);
	nwimage = mlx_xpm_file_to_image(data->mlx, data->file->config->NO, &y, &y);
	data->ww = (int *)mlx_get_data_addr(wwimage, &y, &y, &y);
	data->ew = (int *)mlx_get_data_addr(ewimage, &y, &y, &y);
	data->sw = (int *)mlx_get_data_addr(swimage, &y, &y, &y);
	data->nw = (int *)mlx_get_data_addr(nwimage, &y, &y, &y);
}

void	init_images(t_data *data)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	data->file->config->NO = ft_substr(data->file->config->NO, 0, ft_strlen(data->file->config->NO) - 1);
	data->file->config->SO = ft_substr(data->file->config->SO, 0, ft_strlen(data->file->config->SO) - 1);
	data->file->config->WE = ft_substr(data->file->config->WE, 0, ft_strlen(data->file->config->WE) - 1);
	data->file->config->EA = ft_substr(data->file->config->EA, 0, ft_strlen(data->file->config->EA) - 1);
	fd1 = open(data->file->config->NO, O_RDONLY);
	fd2 = open(data->file->config->SO, O_RDONLY);
	fd3 = open(data->file->config->WE, O_RDONLY);
	fd4 = open(data->file->config->EA, O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		printf("Error\n please check the path of the images\n");
		exit(1);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}

void	check_if_info_file(t_data *data)
{
	if (data->file->config->NO == NULL)
		print_error("Unknown NO image");
	if (data->file->config->SO == NULL)
		print_error("Unknown SO image");
	if (data->file->config->WE == NULL)
		print_error("Unknown WE image");
	if (data->file->config->EA == NULL)
		print_error("Unknown EA image");
	if (data->file->config->F == NULL)
		print_error("Unknown floor color");
	if (data->file->config->C == NULL)
		print_error("Unknown ceil color");
}

int	get_color(char *line)
{
	int	r;
	int	g;
	int	b;
	int	camma;

	camma = -1;
	while (*line && *line != '\n')
	{
		if (camma == -1)
		{
			r = ft_atoi(line);
			camma = 0;
		}
		if ((ft_isdigit(*line) || *line == ',') && camma <= 2)
		{
			if (*line == ',')
			{
				if (camma == 0)
					g = ft_atoi((line + 1));
				else if (camma == 1)
					b = ft_atoi((line + 1));
				camma++;
			}
			line++;
		}
	}
	return (convert_color(r, g, b));
}
