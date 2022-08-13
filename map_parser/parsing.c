/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:31:38 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/07 12:31:42 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    setPlayerpos(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == 'N')
            {
                data->player->player_x = (x * 64);
                data->player->player_y = (y * 64);
                break;
            }
            x++;
        }
        y++;
    }
}

int get_index(char *line)
{
	int i;

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
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i - 1); 
}

int map_close_check(t_data *data)
{
	char **map;
	int x;
	int y;
	int i;

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
		if (map[data->file->file_line - 1][x] != '1' && map[data->file->file_line - 1][x] != ' ')
			return (0);
		x++;
	}
	return (1);
}

int	ft_check_map(t_data *data)
{
	setPlayerpos(data);
	return (map_close_check(data));
}

int	store_images(t_data *data, char *line)
{
	int	i;
	int	j;

	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (ft_isprint(line[j]) && line[j] != ' ' && line[j] != '\t')
		j++;
	if (ft_strncmp(line, "NO", 2) == 0)
		data->file->config->NO = ft_substr(line, i, j);
	else if (ft_strncmp(line, "SO", 2) == 0)
		data->file->config->SO = ft_substr(line, i, j);
	else if (ft_strncmp(line, "WE", 2) == 0)
		data->file->config->WE = ft_substr(line, i, j);
	else if (ft_strncmp(line, "EA", 2) == 0)
		data->file->config->EA = ft_substr(line, i, j);
	return (1);
}

int	check_if_rgb(char *line)
{
	int	camma;

	camma = 0;
	while (*line && *line != '\n')
	{
		if (camma == 0 && *line == ',' && !ft_isdigit(*(line - 1)))
			return (-1);
		if ((ft_isdigit(*line) || *line == ',') && camma <= 2)
		{
			if (ft_isdigit(*line) && ft_atoi(line) > 255)
				return (-1);
			else if (*line == ',')
			{
				if (!ft_isdigit(*(line + 1)))
					return (-1);
				camma++;
			}
			line++;
		}
		else
			return (-1);
	}
	return (1);
}

int	store_f_ce_color(t_data *data, char *line)
{
	int	i;
	int	j;
	int error;

	i = 1;
	error = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (ft_isprint(line[j]))
		j++;
	if (ft_strncmp(line, "F", 1) == 0)
		data->file->config->F = ft_substr(line, i, j);
	if (ft_strncmp(line, "C", 1) == 0)
		data->file->config->C = ft_substr(line, i, j);
	if (data->file->config->F)
        error = check_if_rgb(data->file->config->F);
    if (data->file->config->C)
        error = check_if_rgb(data->file->config->C);
	return (error);
}

int	get_valide_info(t_data *data, char *line)
{
	int	result;

	result = 0;
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
     || ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0) 
		result = store_images(data, line);
	else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		result = store_f_ce_color(data, line);
	if (result == -1)
	{
		printf("Error\ninvalid color\n");
		exit(1);
	}
	return (result);
}
