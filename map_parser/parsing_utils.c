/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:30 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 14:11:04 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_down(char **map, int y, int x)
{
	if (map[y + 1] && x >= (int)ft_strlen(map[y + 1]))
		return (0);
	else if (map[y + 1] && (int)ft_strlen(map[y + 1]) > x)
	{
		if (map[y + 1][x] == '0')
			return (0);
	}
	return (1);
}

int	check_top(char **map, int y, int x)
{
	if (y != 0 && (int)ft_strlen(map[y - 1]) < x)
		return (0);
	if (y != 0 && (int)ft_strlen(map[y - 1]) > x)
	{
		if (map[y - 1][x] == '0')
			return (0);
	}
	return (1);
}

int	ft_check_map(t_data *data)
{
	setplayerpos(data);
	if (data->file->n_player == 0)
		print_error("add 1 player to the map!");
	if (check_close(data) == 0)
		return (0);
	return (map_close_check(data));
}
