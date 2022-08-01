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

char **malloc_map(int fd, t_file *file)
{
    char *line;
    char **map;

    if (fd < 0)
    {
        perror(file->file_name);
        exit(1);
    }
	line = get_next_line(fd);
	if (!line || line[0] == 0)
	{
		free(line);
		exit(1);
	}
    while(line)
    {
        free(line);
        file->file_line += 1;
        line = get_next_line(fd);
    }
    map = malloc(sizeof(char *) * file->file_line  + 1);
    if (!map)
        free_map(map, file->file_line, "Error in the map");
    return (map);
}

char	**ft_get_map(int fd, char **map, t_file *file)
{
	int	i;

	i = 0;
	map[0] = get_next_line(fd);
    file->file_width = ft_strlen(map[i]) - 1;
	if (!map[i])
	{
		free(map[i]);
		error_1();
	}
	i++;
	while (i < file->file_line)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			free_map(map, i, "error in map");
        if(ft_strlen(map[i]) > file->file_width)
            file->file_width = ft_strlen(map[i]) - 1;
		i++;
	}
    map[i] = NULL;
	return (map);
}

int check_info(char *line)
{
    if (ft_strncmp(line, "NO", 3) == 0)
        return (1);
    if (ft_strncmp(line, "SO", 3) == 0)
        return (2);
    if (ft_strncmp(line, "WE", 3) == 0)
        return (3);
    if (ft_strncmp(line, "EA", 3) == 0)
        return (4);
    if (ft_strncmp(line, "F", 2) == 0)
        return (5);
    if (ft_strncmp(line, "C", 2) == 0)
        return (6);
    return (-1);
}

int check_config_file(int fd, t_file *file)
{
    char *line;

    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    file->config = malloc(sizeof (t_config));
    file->config->WE = malloc(sizeof (char));
    file->config->SO = malloc(sizeof (char));
    file->config->NO = malloc(sizeof (char));
    file->config->EA = malloc(sizeof (char));
    file->config->C = malloc(sizeof (char));
    file->config->F = malloc(sizeof (char));
    while (line)
    {
        if (!line || line[0] == 0)
        {
            free(line);
            exit(1);
        }
        if (check_info(line) == -1)
        {
            free(line);
            exit(1);
        }
        else
        {
            if (check_info(line) == 1)
                file->config->NO = &line[3];
            else if (check_info(line) == 2)
                file->config->SO = &line[3];
            else if (check_info(line) == 3)
                file->config->WE =  &line[3];
            else if (check_info(line) == 4)
                file->config->EA = &line[3];
            else if (check_info(line) == 5)
                file->config->F = &line[2];
            else if (check_info(line) == 6)
                file->config->C = &line[2];
        }
        line = get_next_line(fd);
    }
    return (0);
}


