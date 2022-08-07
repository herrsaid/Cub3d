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
        {
            printf("hhh no\n");
            line = get_next_line(fd);
            free(line);
        }
        else if (line[0] != '1')
        {
            
            if (get_valide_info(data, line))
            {
                printf("okey hhh\n");
                line = get_next_line(fd);
                free(line);
            }
        }
        else
        {
            printf("wi hhh\n");
            file->file_line += 1;
            line = get_next_line(fd);
            free(line);
        }
	}
    printf("================\n");
    printf("%s\n", file->config->C);
    printf("%s\n", file->config->F);
    printf("%s\n", file->config->EA);
    printf("%s\n", file->config->NO);
    printf("%s\n", file->config->SO);
    printf("%s\n", file->config->WE);
    map = malloc(sizeof(char *) * file->file_line  + 1);
    if (!map)
        free_map(map, file->file_line, "Error in the map");
    return (map);
}

char	**ft_get_map(int fd, char **map, t_file *file)
{
	int	i;
    char *line;

	i = 0;
    file->file_width = 0;
    line = get_next_line(fd);
	while (i < file->file_line)
	{
        if (!empty_line(line) && *line == '1')
        {
            map[i] = line;
	        if (!map[i])
			    free_map(map, i, "error in map");
            if(ft_strlen(map[i]) > file->file_width)
                file->file_width = ft_strlen(map[i]) - 1;
		    i++;
        }
        line = get_next_line(fd);
	}
    map[i] = NULL;
	return (map);
}


