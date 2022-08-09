/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:56:22 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/07 12:56:26 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_if_border(t_data *data, int y, int x)
{
	if (y == 0 || x == 0 || 
    y == data->file->file_line - 1 
    || x == data->file->file_width - 1)
		return (1);
	return (0);
}

int	is_wa_sp(char c)
{
	if (c == '0' || c == ' ' || c == '1')
		return (1);
	return (0);
}

int	check_v_c(char c)
{
	if (c == '0' || c == '1' || c == 'N' 
    || c == 'S' || c == 'E' || c == 'W' || c == ' ')
		return (1);
	return (0);
}

int	player_pos(t_data *data, int y, int x)
{
	// if (data->player->player_x == -1 && data->player->player_y == -1)
	// {
		//data->player->pdx = 0;
		//data->player->pdy = 0;
		//data->player->pa = 0;
		data->player->player_x = x * 32;
		data->player->player_y = y * 32;
		return (1);
	// }
	// else
	// 	return (0);
}