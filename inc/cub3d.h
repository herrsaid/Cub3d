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
#define W_H 640
#define W_W 640
#define DR 0.0174533
#define FOV 60 * (PI / 180)
#include "../map_parser/map.h"

typedef struct s_player
{
    float player_x;
    float player_y;
    float pa;
    float pdx;
    float pdy;
}   t_player;

typedef struct s_screen{
    int s_width;
    int s_height;
    int s_halfwdith;
    int s_halfheight;

} t_screen;

typedef struct s_ray{
    float rayx;
    float rayy;
    float rayangle;
    int isfacingup;
    int isfacingdown;
    int isfacingright;
    int isfacingleft;
    float rendx;
    float rendy;
} t_ray;

typedef struct s_data
{
    void        *mlx;
    void        *win;
    t_player    *player;
    t_file      *file;
    t_ray       *ray;
    t_screen    *screen;
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
void    draw_line(t_data *data, float bx, float by, float endx, float endy, int color);
float   degtorad(float deg);
int     iswall(float x, float y, t_data *data);
void    castray(t_data *data);
int     convert_color(t_color *color);

#endif
