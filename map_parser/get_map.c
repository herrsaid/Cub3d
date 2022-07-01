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
    line = get_next_line(fd);
    while(line)
    {
        file->file_line += 1;
        line = get_next_line(fd);
        free(line);
    }
    map = malloc(sizeof(char *) * file->file_line  + 1);
    if (!map)
        return (0);
    return (map);
}

char **get_map(int fd, t_file *file)
{
    char **map;

    if (fd <= 0)
        return (0);
    map = malloc_map(fd, file);
    if (!map)
        return (0);
    return  (map);
}

