/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:37:57 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 15:17:54 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_game(t_data *data)
{
	data->ccolor = get_color(data->file->config->c, data);
	data->fcolor = get_color(data->file->config->f, data);
	data->player = (t_player *)malloc(sizeof(t_player));
	data->ray = (t_ray *)malloc(sizeof(t_ray));
	data->player->pa = degtorad(90);
	if (!ft_check_map(data))
		print_error("map not closed!");
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

	wwimage = mlx_xpm_file_to_image(data->mlx, data->file->config->we, &y, &y);
	ewimage = mlx_xpm_file_to_image(data->mlx, data->file->config->ea, &y, &y);
	swimage = mlx_xpm_file_to_image(data->mlx, data->file->config->so, &y, &y);
	nwimage = mlx_xpm_file_to_image(data->mlx, data->file->config->no, &y, &y);
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

	sub_image_name(data);
	fd1 = open(data->file->config->no, O_RDONLY);
	fd2 = open(data->file->config->so, O_RDONLY);
	fd3 = open(data->file->config->we, O_RDONLY);
	fd4 = open(data->file->config->ea, O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
		print_error("please check the path of the images");
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}

void	check_if_info_file(t_data *data)
{
	if (data->file->config->no == NULL)
		print_error("Unknown no image");
	if (data->file->config->so == NULL)
		print_error("Unknown so image");
	if (data->file->config->we == NULL)
		print_error("Unknown we image");
	if (data->file->config->ea == NULL)
		print_error("Unknown ea image");
	if (data->file->config->f == NULL)
		print_error("Unknown floor color");
	if (data->file->config->c == NULL)
		print_error("Unknown ceil color");
}

int	get_color(char *line, t_data *data)
{
	int	camma;

	camma = -1;
	while (*line && *line != '\n')
	{
		if (camma == -1)
		{
			data->r = ft_atoi(line);
			camma = 0;
		}
		if ((ft_isdigit(*line) || *line == ',') && camma <= 2)
		{
			if (*line == ',')
			{
				if (camma == 0)
					data->g = ft_atoi((line + 1));
				else if (camma == 1)
					data->b = ft_atoi((line + 1));
				camma++;
			}
			line++;
		}
	}
	return (convert_color(data->r, data->g, data->b));
}
