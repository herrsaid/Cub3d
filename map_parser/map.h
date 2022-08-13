/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:47:00 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/13 17:47:02 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include  "../Libft/libft.h"

# define BUFFER_SIZE 1

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_config;

typedef struct s_file
{
	int			file_line;
	int			file_width;
	char		*file_name;
	int			n_player;
	t_config	*config;

}	t_file;

void	free_map(char **map, int line, char *error);
char	**ft_get_map(int fd, char **map, t_file *file);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchrr(char *s, int c);
char	*ft_strjoinn(char *s1, char *s2);
char	*get_next_line(int fd);
void	error_1(void);
void	ft_putstr(char *err);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	v_map_e(t_file *file, char **map);
int		is_w_e(char c, t_file *file, int i, int j);
int		empty_line(char *line);

#endif
