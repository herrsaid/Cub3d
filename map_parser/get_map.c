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
		i++;
	}
	return (map);
}


