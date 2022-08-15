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
	if (keycode == 0x7c || keycode == 0x02)
		r_right(data);
	else if (keycode == 0x7B || keycode == 0x00)
		r_left(data);
	else if (keycode == 0x7D || keycode == 0x01)
		move_up(data);
	else if (keycode == 0x7E || keycode == 0x0D)
		move_down(data);
	castray(data);
	draw_mini_map(data);
	return (0);
}

int	move_r(int keycode, t_data *data)
{
	mlx_clear_window (data->mlx, data->win);
	if (keycode == 0x35)
		close_win(data);
	if (keycode == 0x7c || keycode == 0x02)
		r_right(data);
	else if (keycode == 0x7B || keycode == 0x00)
		r_left(data);
	else if (keycode == 0x7D || keycode == 0x01)
		move_up(data);
	else if (keycode == 0x7E || keycode == 0x0D)
		move_down(data);
	castray(data);
	draw_mini_map(data);
	return (0);
}
