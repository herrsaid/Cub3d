/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:49:00 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 13:54:02 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../inc/cub3d.h"

int	empty_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '\0' || *line == '\n')
		return (1);
	return (0);
}

void	init_config(t_data *data)
{
	data->file->config = malloc(sizeof(t_config));
	data->file->config->c = NULL;
	data->file->config->ea = NULL;
	data->file->config->f = NULL;
	data->file->config->no = NULL;
	data->file->config->so = NULL;
	data->file->config->we = NULL;
}

char	**malloc_map(int fd, t_file *file, t_data *data)
{
	char	*line;
	char	**map;

	if (fd < 0)
	{
		perror(file->file_name);
		exit(1);
	}
	line = get_next_line(fd);
	init_config(data);
	while (line)
	{
		if (empty_line(line))
			line = get_next_line(fd);
		else if (line[0] != '1' && line[0] != ' ' && line[0] != '\t' && line[0] != '0')
		{
			if (get_valide_info(data, line))
				line = get_next_line(fd);
		}
		else
		{
			file->file_line += 1;
			line = get_next_line(fd);
		}
		free(line);
	}
	map = malloc(sizeof(char *) * file->file_line + 1);
	return (map);
}

char	**ft_get_map(int fd, char **map, t_file *file)
{
	int		i;
	char	*line;
	int		check;
	int		check2;

	i = 0;
	check = 0;
	check2 = 0;
	line = get_next_line(fd);
	while (i < file->file_line)
	{
		if (ft_strncmp(line, "C", 1) == 0)
			check = 1;
		else if (check2 && empty_line(line))
			print_error("there an error int the map!");
		else if (!empty_line(line) && check)
		{
			check2 = 1;
			map[i] = line;
			if (ft_strlen(map[i]) > file->file_width)
				file->file_width = ft_strlen(map[i]) - 1;
			i++;
		}
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}
