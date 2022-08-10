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
#define W_W 840
#define DR 0.0174533
#define FOV (60 * (PI / 180))
#define SW 1
#define NW 2
#define WW 3
#define EW 4
#include  "../Libft/libft.h"
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
    int iswallhitvirtical;
    int iswallhithorizontal;
    int walldir;
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
    int x_xpm;
    int ccolor;
    int fcolor;
    int *buffer;
    void *image;
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
int     convert_color(int r, int g, int b);
double  calc_dist(float x1, float x2, float y1, float y2);
void    draw_wall(double walh, int i, t_ray *ray, int *buffer, t_data *data);
void    draw_c(double walh, int *buffer, int i, int color);
void    rayinit(t_data *data, float rayangle);
void    find_intersiction(t_data *data, t_ray *ray);
int     *get_buffer_img(void *image);
void    calc_wall_h(t_data *data, t_ray *ray);
void    draw_f(double walh, int *buffer, int i, int color);
//parsing
int	    ft_check_map(t_data *data);
int	    store_images(t_data *data, char *line);
int	    check_if_rgb(char *line);
int	    store_f_ce_color(t_data *data, char *line);
int	    get_valide_info(t_data *data, char *line);
//utils
int	check_player(char c);
int	check_if_border(t_data *data, int y, int x);
int	is_wa_sp(char c);
int	check_v_c(char c);
int	player_pos(t_data *data, int y, int x);
char  **malloc_map(int fd, t_file *file, t_data *data);
int get_color(char *line);
void check_if_info_file(t_data *data);
void draw_mini_map(t_data *data);
float   normalizeAngle(float angle);

#endif
