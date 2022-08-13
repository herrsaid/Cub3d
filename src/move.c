/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2021/12/20 20:40:15 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/13 13:03:18 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int	r_right(t_data *data)
{
	data->player->pa += 1 * degtorad(8);
	return (0);
}

int	r_left(t_data *data)
{
	data->player->pa += -1 * degtorad(8);
	return (0);
}

int	move_down(t_data *data)
{
	float	newx;
	float	newy;

	newx = data->player->player_x + cos(data->player->pa) * 20;
	newy = data->player->player_y + sin(data->player->pa) * 20;
	if (data->map[(int)newy / 64][(int)newx / 64] != '1')
	{
		data->player->player_x = newx;
		data->player->player_y = newy;
	}
	return (0);
}

int	move_up(t_data *data)
{
	float	newx;
	float	newy;

	newx = data->player->player_x - cos(data->player->pa) * 20;
	newy = data->player->player_y - sin(data->player->pa) * 20;
	if (data->map[(int)newy / 64][(int)newx / 64] != '1')
	{
		data->player->player_x = newx;
		data->player->player_y = newy;
	}
	return (0);
}
