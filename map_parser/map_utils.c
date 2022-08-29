/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:56:16 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/16 16:16:57 by selhanda         ###   ########.fr       */
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
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

void	player_pos(t_data *data, int x, int y, char c)
{
	if (c == 'N')
		data->player->pa = degtorad(270);
	else if (c == 'E')
		data->player->pa = degtorad(0);
	else if (c == 'W')
		data->player->pa = degtorad(180);
	else if (c == 'S')
		data->player->pa = degtorad(90);
	data->player->player_x = x * 64;
	data->player->player_y = y * 64;
}

void	ft_get_map_norm(char *line, int *check, int check2)
{
	if (ft_strncmp(line, "C", 1) == 0)
		*check = 1;
	else if (check2 && empty_line(line))
		print_error("empty line in the map!");
}
