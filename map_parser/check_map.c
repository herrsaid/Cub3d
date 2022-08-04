/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:22:59 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/04 12:23:11 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_w_e(char c, t_file *file, int i, int j)
{
	if (c == '1')
		return (0);
	else if (c == '0')
		return (0);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		(file->n_player)++;
		if (file->n_player != 1)
			return (1);
		return (0);
	}
	return (1);
}

void	v_map_e(t_file *file, char **map)
{  
    if (file->n_player == 0)
		free_map(map, file->file_line, "error : no player in the map");
}

void	ft_check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] && data->map && i < data->file->file_line)
	{
		j = 0;
		while (data->map[i][j] && j < data->file->file_line - 1)
		{
			if ((i == 0 || i == data->file->file_width - 1) && data->map[i][j] != '1')
				free_map(data->map, i, "error : map not closed");
			if ((j == 0 || j == data->file->file_line - 1) && data->map[i][j] != '1')
				free_map(data->map, i, "error : map not closed");
			else if (is_w_e(data->map[i][j], data->file, i, j))
				free_map(data->map, i, "error : wrong element in the map");
			j++;
		}
		i++;
	}
	v_map_e(data->file, data->map);
}
