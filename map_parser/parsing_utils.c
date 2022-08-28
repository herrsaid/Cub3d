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

void	setplayerpos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->file->file_line)
	{
		x = 0;
		while (x < data->file->file_width - 1)
		{
			if (data->file->n_player > 1)
				print_error("accept 1 player only!");
			if (!check_v_c(data->map[y][x]) && ft_isprint(data->map[y][x]))
				print_error("invalid caracter in the map!");
			if (check_player(data->map[y][x]))
			{
				player_pos(data, x, y, data->map[y][x]);
				data->file->n_player += 1;
			}
			x++;
		}
		y++;
	}
}

int	get_index(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (i);
		i++;
	}
	return (0);
}

int	get_last(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i - 1);
}

int	map_close_check(t_data *data)
{
	char	**map;
	int		x;
	int		y;
	int		i;

	map = data->map;
	x = 0;
	y = 0;
	while (map[y][x] && map[y][x] != '\n')
	{
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (0);
		x++;
	}
	x = 0;
	i = 0;
	while (i < data->file->file_line)
	{
		if (map[i][get_index(map[i])] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->file->file_line)
	{
		if (map[i][get_last(map[i])] != '1')
			return (0);
		i++;
	}
	while (map[data->file->file_line - 1][x])
	{
		if (map[data->file->file_line - 1][x] != '1'
				&& map[data->file->file_line - 1][x] != ' ')
			return (0);
		x++;
	}
	return (1);
}

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

int	check_sides(char **map, int x, int y)
{
	if ((int)ft_strlen(map[y]) >= (x + 1))
	{
		if (map[y][x + 1] == '0')
			return (0);
	}
	if (x > 0)
	{
		if (map[y][x - 1] == '0')
			return (0);
	}
	if (check_down(map, y, x) == 0)
		return (0);
	if (check_top(map, y, x) == 0)
		return (0);
	return (1);
}

int	ft_check_zero(char **map, int y, int x)
{
	if ((y - 1) != 0 && ((int)ft_strlen(map[y - 1]) - 1) <= x)
		return (0);
	if ((y + 1) && ((int)ft_strlen(map[y + 1]) - 1) <= x)
		return (0);
	return (1);
}

int	check_close(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (map[y][x] == '0')
			{
				if (ft_check_zero(map, y, x) == 0)
					return (0);
			}
			else if (map[y][x] == ' ')
			{
				if (!check_sides(map, x , y))
					return (0);
			}
			x++;	
		}
		y++;
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
