/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:02:33 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 14:05:01 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
		data->file->config->no = ft_substr(line, i, j);
	else if (ft_strncmp(line, "SO", 2) == 0)
		data->file->config->so = ft_substr(line, i, j);
	else if (ft_strncmp(line, "WE", 2) == 0)
		data->file->config->we = ft_substr(line, i, j);
	else if (ft_strncmp(line, "EA", 2) == 0)
		data->file->config->ea = ft_substr(line, i, j);
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
	int	error;

	i = 1;
	error = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (ft_isprint(line[j]))
		j++;
	if (ft_strncmp(line, "F", 1) == 0)
		data->file->config->f = ft_substr(line, i, j);
	if (ft_strncmp(line, "C", 1) == 0)
		data->file->config->c = ft_substr(line, i, j);
	if (data->file->config->f)
		error = check_if_rgb(data->file->config->f);
	if (data->file->config->c)
		error = check_if_rgb(data->file->config->c);
	return (error);
}

int	get_valide_info(t_data *data, char *line)
{
	int	result;

	result = 0;
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0)
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
