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
    int i = 0;
    int y = -90;
	if (keycode == 0x35)
		close_win(data);
	if (keycode == 0x7C || keycode == 0x02)
	    move_right(data);
	else if (keycode == 0x7B || keycode == 0x00)
	    move_left(data);
	else if (keycode == 0x7D || keycode == 0x01)
	    move_up(data);
	else if (keycode == 0x7E || keycode == 0x0D)
	    move_down(data);
    ft_drwa2dmap(data);
    while (i < 60)
    {
        draw_line(data, data->player->player_x , data->player->player_y + 6, 0 , data->player->player_y - y);
        i++;
        y += 5;
    }
    ft_display(data->player->player_x, data->player->player_y, data, 16711680, 12);
    return (0);
}

int	move_right(t_data *data)
{
    mlx_clear_window (data->mlx, data->win);
    data->player->player_x += 12;
    return (0);
}

int	move_left(t_data *data)
{
	mlx_clear_window (data->mlx, data->win);
	data->player->player_x -= 12;
	return (0);
}

int	move_down(t_data *data)
{
	mlx_clear_window (data->mlx, data->win);
	data->player->player_y -= 12;
	return (0);
}

int	move_up(t_data *data)
{
	mlx_clear_window (data->mlx, data->win);
	data->player->player_y += 12;
	return (0);
}
