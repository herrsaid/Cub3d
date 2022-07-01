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
#define MAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
#define BUFFER_SIZE 1

typedef struct s_file
{
    int file_line;
    char *file_name;
}   t_file;

void	free_map(char **map, int line, char *error);
char    **malloc_map(int fd, t_file *file);
char	**ft_get_map(int fd, char **map, t_file *file);
int	    ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	error_1(void);
void	ft_putstr(char *err);

#endif