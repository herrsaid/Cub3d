/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:35:35 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 16:30:55 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double	calc_dist(float x1, float x2, float y1, float y2)
{
	return (sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))));
}

int	convert_color(int r, int g, int b)
{
	return ((r * 65536) + (g * 256) + (b));
}

void	draw_mini_map(t_data *data)
{
	ft_drwa2dmap(data);
	ft_display((data->player->player_x - 4) / 8,
		(data->player->player_y - 4) / 8, data, 4);
}

int	*get_buffer_img(void *image)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int	*buffer;

	buffer = (int *)mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	line_bytes /= 4;
	return (buffer);
}

int	move_up(t_data *data)
{
	float	newx;
	float	newy;

	newx = data->player->player_x - cos(data->player->pa) * 20;
	newy = data->player->player_y - sin(data->player->pa) * 20;
	if (data->map[(int)newy / 64][(int)newx / 64] == '0' ||
	data->map[(int)newy / 64][(int)newx / 64] == 'S' ||
	data->map[(int)newy / 64][(int)newx / 64] == 'E' ||
	data->map[(int)newy / 64][(int)newx / 64] == 'N' ||
	data->map[(int)newy / 64][(int)newx / 64] == 'W')
	{
		data->player->player_x = newx;
		data->player->player_y = newy;
	}
	return (0);
}
