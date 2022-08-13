/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2022/08/07 12:56:22 by selhanda          #+#    #+#             */
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

int	check_v_c(char c)
{
	if (c == '0' || c == '1' || c == 'N' 
    || c == 'S' || c == 'E' || c == 'W' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	player_pos(t_data *data, int y, int x)
{
		data->player->player_x = x * 64;
		data->player->player_y = y * 64;
		return (1);
}