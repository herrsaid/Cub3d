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
# include <math.h>
#define PI 3.1415926535
#define DR 0.0174533
#define P2 PI/2
#define P3 3*PI/2
#include "../map_parser/map.h"

typedef struct t_player
{
    float player_x;
    float player_y;
    float pa;
    float pdx;
    float pdy;
}   t_player;

typedef struct s_data
{
    void        *mlx;
    void        *win;
    t_player    *player;
    t_file      *file;
    char        **map;
}	t_data;


int	    des_b(t_data *data);
void	close_win(t_data *data);
int	    move_f(int keycode, t_data *data);
void    drawPlayer(void *mlx, void *win, float px, float py);
int	    r_right(t_data *data);
int	    move_up(t_data *data);
int	    move_down(t_data *data);
int     r_left(t_data *data);
void	check_file(char *str);
void	init_file(t_file *file, char *filename);
void    ft_drwa2dmap(t_data *cub);
void    ft_display(int x, int y, t_data *cub, int color, int size);
void    draw_line(t_data *data, float bx, float by, float endx, float endy);
void    draw_m_line(t_data *data);

#endif
