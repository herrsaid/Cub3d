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
#include  "../Libft/libft.h"

#define BUFFER_SIZE 1

typedef struct s_config
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    char *F;
    char *C;
}   t_config;

typedef struct s_file
{
    int         file_line;
    int         file_width;
    char        *file_name;
    int         n_player;
    t_config    *config;

}   t_file;

void	free_map(char **map, int line, char *error);
char	**ft_get_map(int fd, char **map, t_file *file);
int	    ft_strcmp(const char *s1, const char *s2);
char	*ft_strchrr(char *s, int c);
char	*ft_strjoinn(char *s1, char *s2);
char	*get_next_line(int fd);
void	error_1(void);
void	ft_putstr(char *err);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
void	v_map_e(t_file *file, char **map);
int	    is_w_e(char c, t_file *file, int i, int j);
int	    empty_line(char *line);

#endif