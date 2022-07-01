/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:43:43 by selhanda          #+#    #+#             */
/*   Updated: 2022/06/27 17:43:48 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
#include "../map_parser/map.h"

typedef struct t_player
{
    float player_x;
    float player_y;
}   t_player;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_player *player;
    t_file *file;
    char    **map;
}	t_data;


int	    des_b(t_data *data);
void	close_win(t_data *data);
int	    move_f(int keycode, t_data *data);
void    drawPlayer(void *mlx, void *win, float px, float py);
int	    move_right(t_data *data);
int	    move_up(t_data *data);
int	    move_down(t_data *data);
int	    move_left(t_data *data);
void    ft_display(int x, int y, t_data *cub);
void	error_1(void);
void	check_file(char *str);
void	init_file(t_file *file, char *filename);

#endif
