/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:11:42 by salamane          #+#    #+#             */
/*   Updated: 2022/07/01 12:11:46 by salamane         ###   ########.fr       */
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

void init_config(t_data *data)
{
    data->file->config = malloc(sizeof(t_config));
    data->file->config->C = NULL;
    data->file->config->EA = NULL;
    data->file->config->F = NULL;
    data->file->config->NO = NULL;
    data->file->config->SO = NULL;
    data->file->config->WE = NULL;
}

char **malloc_map(int fd, t_file *file, t_data *data)
{
    char *line;
    char **map;

    if (fd < 0)
    {
        perror(file->file_name);
        exit(1);
    }
    line = get_next_line(fd);
    init_config(data);
    while(line)
    {
        if (empty_line(line))
            line = get_next_line(fd);

        else if (line[0] != '1' && line[0] != ' ' && line[0] != '\t')
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
    map = malloc(sizeof(char *) * file->file_line  + 1);
    return (map);
}

char	**ft_get_map(int fd, char **map, t_file *file)
{
	int	i;
    char *line;
    int check;

	i = 0;
    file->file_width = 0;
    check = 0;
    line = get_next_line(fd);
	while (i < file->file_line)
	{
        if (ft_strncmp(line, "C", 1) == 0)
            check = 1;
        else if (!empty_line(line) && check)
        {
            map[i] = line;
            if(ft_strlen(map[i]) > file->file_width)
                file->file_width = ft_strlen(map[i]) - 1;
		    i++;
        }
        line = get_next_line(fd);
	}
    map[i] = NULL;
	return (map);
}


