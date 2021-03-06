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

void draw_m_line(t_data *data)
{
    int i = 0;
    int y ;

    y = -360;
    while (i < 1)
    {
        draw_line(data, data->player->player_x,
                  data->player->player_y,
                  data->player->player_x + data->player->pdx * 30,
                  data->player->player_y + data->player->pdy * 30);
        i++;
        y += 15;
    }
}


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
    ft_display(data->player->player_x, data->player->player_y, data, 16711680, 12);
    draw_m_line(data);
    return (0);
}

int	r_right(t_data *data)
{
    data->player->pa += 0.1;
    if (data->player->pa > 2 * PI)
        data->player->pa -= 2 * PI;
    data->player->pdx = cos(data->player->pa) * 12;
    data->player->pdy = sin(data->player->pa) * 12;
    return (0);
}

int	r_left(t_data *data)
{
    data->player->pa -= 0.1;
    if (data->player->pa < 0)
        data->player->pa += 2 * PI;
    data->player->pdx = cos(data->player->pa) * 12;
    data->player->pdy = sin(data->player->pa) * 12;
	return (0);
}

int	move_down(t_data *data)
{
    data->player->player_x += data->player->pdx;
    data->player->player_y += data->player->pdy;
    return (0);
}

int	move_up(t_data *data)
{
    data->player->player_x -= data->player->pdx;
    data->player->player_y -= data->player->pdy;
	return (0);
}
