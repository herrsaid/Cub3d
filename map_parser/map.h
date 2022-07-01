/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:08:07 by salamane          #+#    #+#             */
/*   Updated: 2022/07/01 12:08:10 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define    MAP_H

#include "gnl/get_next_line.h"

typedef struct s_file
{
    int file_line;
    char *file_name;
}   t_file;

void	free_map(char **map, int line, char *error);
char    **malloc_map(int fd, t_file *file);
char	**ft_get_map(int fd, char **map, t_file *file);

#endif