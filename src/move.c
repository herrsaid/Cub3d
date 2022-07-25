/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:40:15 by selhanda          #+#    #+#             */
/*   Updated: 2021/12/21 14:53:40 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	move_f(int keycode, t_data *data)
{
	if (keycode == 0x35)
		close_win(data);
	if (keycode == 0x7C || keycode == 0x02)
	    r_right(data);
	else if (keycode == 0x7B || keycode == 0x00)
	    r_left(data);
	else if (keycode == 0x7D || keycode == 0x01)
	    move_up(data);
	else if (keycode == 0x7E || keycode == 0x0D)
	    move_down(data);
    mlx_clear_window (data->mlx, data->win);
    ft_drwa2dmap(data);
    ft_display(data->player->player_x - 6, data->player->player_y - 6, data, 16711680, 12);
    castray(data);
    return (0);
}

int	r_right(t_data *data)
{
    // data->player->pa += 0.1;
    // if (data->player->pa > 2 * PI)
    //     data->player->pa -= 2 * PI;
    // data->player->pdx = cos(data->player->pa) * 12;
    // data->player->pdy = sin(data->player->pa) * 12;
    // return (0);
    data->player->pa += 1 * degtorad(8);
    return (0);
}

int	r_left(t_data *data)
{
    // data->player->pa -= 0.1;
    // if (data->player->pa < 0)
    //     data->player->pa += 2 * PI;
    // data->player->pdx = cos(data->player->pa) * 12;
    // data->player->pdy = sin(data->player->pa) * 12;
    data->player->pa += -1 * degtorad(8);
	return (0);
}

int	move_down(t_data *data)
{
    float newx = data->player->player_x + cos(data->player->pa) * 12;
    float newy = data->player->player_y + sin(data->player->pa) * 12;
    if (data->map[(int)(newy / 32)][(int)(newx / 32)] != '1')
    {
        data->player->player_x = newx;
        data->player->player_y = newy;
    }
    return (0);
}

int	move_up(t_data *data)
{
    float newx = data->player->player_x - cos(data->player->pa) * 12;
    float newy = data->player->player_y - sin(data->player->pa) * 12;
    if (data->map[(int)(newy / 32)][(int)(newx / 32)] != '1')
    {
        data->player->player_x = newx;
        data->player->player_y = newy;
    }
	return (0);
}
