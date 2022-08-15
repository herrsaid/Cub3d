/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:40:05 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 13:40:07 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
