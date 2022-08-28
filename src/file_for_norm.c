/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_for_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:34:27 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 13:34:30 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float	degtorad(float deg)
{
	return (deg * (PI / 180.0));
}

float	normalizeangle(float angle)
{
	if (angle < 0)
		angle = (2 * PI) + angle;
	else if (angle > (2 * PI))
		angle = angle - (2 * PI);
	return (angle);
}

int	move_f(int keycode, t_data *data)
{
	mlx_clear_window (data->mlx, data->win);
	if (keycode == 0x35)
		close_win(data);
	if (keycode == 0x7c)
		r_right(data);
	else if (keycode == 0x7B)
		r_left(data);
	else if (keycode == 0x7D || keycode == 0x01)
		move_up(data);
	else if (keycode == 0x7E || keycode == 0x0D)
		move_down(data);
	else if (keycode == 0x02)
		move_rd(data);
	else if (keycode == 0x00)
		move_l(data);
	castray(data);
	draw_mini_map(data);
	return (0);
}

int	move_r(int keycode, t_data *data)
{
	mlx_clear_window (data->mlx, data->win);
	if (keycode == 0x35)
		close_win(data);
	if (keycode == 0x7c)
		r_right(data);
	else if (keycode == 0x7B)
		r_left(data);
	else if (keycode == 0x7D || keycode == 0x01)
		move_up(data);
	else if (keycode == 0x7E || keycode == 0x0D)
		move_down(data);
	else if (keycode == 0x02)
		move_rd(data);
	else if (keycode == 0x00)
		move_l(data);
	castray(data);
	draw_mini_map(data);
	return (0);
}

void	sub_image_name(t_data *data)
{
	char	*path;

	path = data->file->config->no;
	//free(data->file->config->no);
	data->file->config->no = ft_substr(path, 0, ft_strlen(path) - 1);
	path = data->file->config->so;
	//free(data->file->config->so);
	data->file->config->so = ft_substr(path, 0, ft_strlen(path) - 1);
	path = data->file->config->we;
	//free(data->file->config->we);
	data->file->config->we = ft_substr(path, 0, ft_strlen(path) - 1);
	path = data->file->config->ea;
	//free(data->file->config->ea);
	data->file->config->ea = ft_substr(path, 0, ft_strlen(path) - 1);
}
