/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:46:35 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/13 13:17:14 by selhanda         ###   ########.fr       */
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
    (data->player->player_y - 4) / 8, data, 16711680, 4);
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
