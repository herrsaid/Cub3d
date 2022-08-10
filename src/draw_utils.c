/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:47:21 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/02 16:47:25 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double calc_dist(float x1, float x2, float y1, float y2)
{
    return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

void draw_line(t_data *data, float bx, float by, float endx, float endy, int color)
{
    float dx;
    float dy;
    int pexels;
    float px;
    float py;

    dx = endx - bx;
    dy = endy - by;
    pexels = sqrt((dx * dx) + (dy * dy));
    dx /= pexels;
    dy /= pexels;
    px = bx;
    py = by;
    while (pexels)
    {
        mlx_pixel_put(data->mlx, data->win , px, py, color);
        px += dx;
        py += dy;
        --pexels;
    }
}

int convert_color(int r, int g, int b)
{
    return ((r * 65536) + (g * 256) + (b));
}

void draw_mini_map(t_data *data)
{
    ft_drwa2dmap(data);
    ft_display((data->player->player_x - 56) / 8,
     (data->player->player_y - 56) / 8, data, 16711680, 4);
}

void draw_wall(double walh, int i, t_ray *ray, int *buffer, t_data *data)
{
    int y;
    int color;
    int distfromtop;
    int xofset;
    int yofset;
    int walltop;
    int wallbuttom;

    y = (W_H / 2)  - floor(walh / 2);
    walltop = (W_H / 2)  + floor(walh / 2);
    wallbuttom = (W_H / 2)  + floor(walh / 2);
    if (data->ray->iswallhitvirtical)
        xofset = ((int)data->ray->rayy % 64);
    else if (data->ray->iswallhithorizontal)
        xofset = (int)data->ray->rayx % 64;
    if (y < 0)
        y = 0;
    while (y < (W_H / 2)  + floor(walh / 2))
    {
        distfromtop = y + (walh / 2) - (W_H / 2);
        yofset = distfromtop * ((float) 64 / walh);
        color = data->xpm_pxls[(64 * yofset) + xofset];
        buffer[(W_W * y) + i] = color;
        y++;
    }
}

void draw_c(double walh, int *buffer, int i, int color)
{
    int y;

    y = 0;
    while (y < (W_H / 2)  - floor(walh / 2))
    {
        buffer[(W_W * y) + i] = color;
        y++;
    }  
}

void draw_f(double walh, int *buffer, int i, int color)
{
    int y;

    y = (W_H / 2) +  floor(walh / 2);
    while (y < W_H)
    {
        buffer[(W_W * y) + i] = color;
        y++;
    }
}

int *get_buffer_img(void *image)
{
    int pixel_bits;
    int line_bytes;
    int endian;
    int *buffer;
    
    buffer = (int *)mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
    line_bytes /= 4;
    return (buffer);
}
