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
#define W_H 840
#define W_W 840
#define DR 0.0174533
#define FOV (60 * (PI / 180))
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
    double      dist;
    double      walh;
    void        *xpm_img;
    int         *xpm_pxls;
}	t_data;

int x_xpm;

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
int     convert_color(int r, int g, int b);
double  calc_dist(float x1, float x2, float y1, float y2);
void    draw_wall(double walh, int i, t_ray *ray, int *buffer, t_data *data);
void    draw_c(double walh, int *buffer, int i);
void    rayinit(t_data *data, float rayangle);
void    find_intersiction(t_data *data, t_ray *ray);
int     *get_buffer_img(void *image);
void    calc_wall_h(t_data *data, t_ray *ray);
void    draw_f(double walh, int *buffer, int i);

#endif
