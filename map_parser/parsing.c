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

int	ft_check_map(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->file->file_line)
	{
		x = -1;
		while (++x < data->file->file_width)
		{
			// if (ft_isprint(data->map[y][x]) && data->map[y][x] != '\n' && data->map[y][x] != '\0')
			// {
			// 	printf("=>x = %d y = %d = %c\n", data->map[y][x], x, y);
			// 	if (data->map[y][x] == '\n' || data->map[y][x] == '\0')
			// 			printf("yes\n");
			// 	if (!check_v_c(data->map[y][x]))
			// 		return (0);
			// }
			// else if (check_if_border(data, y, x)
			// 	&& !is_wa_sp(data->map[y][x]))
			// 	return (0);
			if (check_player(data->map[y][x]))
				player_pos(data, y, x);
		}
	}
    return (1);
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
    {
		result = store_f_ce_color(data, line);
    }
	if (result == -1)
	{
		printf("Error\ninvalid color\n");
		exit(1);
	}
	return (result);
}

