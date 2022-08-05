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

void draw_wall(double walh, int i, t_ray *ray, int *buffer, t_data *data)
{
    int y;
    int color;
    int y_xpm;
    int distfromtop;

    y_xpm = 0;
    if (i > 64 && data->x_xpm == 64)
        data->x_xpm = (int)(ray->rayy) % 64;
    // else if (i > 64)
    //     data->x_xpm++;
    else
        data->x_xpm = (int)(ray->rayx) % 64;
    y = (W_H / 2)  - floor(walh / 2);
    color = convert_color(150, 150, 150);
    while (y < (W_H / 2)  + floor(walh / 2))
    {
        if (y_xpm > 64)
            y_xpm = 0;
        distfromtop = y + (walh / 2) - (W_H / 2);
        y_xpm = distfromtop * ((float) 64 / walh);
        color = data->xpm_pxls[(64 * y_xpm) + data->x_xpm];
        if ((int)ray->rayy % 32 == 0)
            color = convert_color(100, 120, 130);
        // else if ((int)ray->rayx % 32 == 0)
        //     color = convert_color(130, 130, 130);
        buffer[(W_W * y) + i] = color;
        y++;
       // y_xpm++;
    }
}

void draw_c(double walh, int *buffer, int i)
{
    int y;

    y = 0;
    while (y < (W_H / 2)  - floor(walh / 2))
    {
        buffer[(W_W * y) + i] = 32511;
        y++;
    }  
}

void draw_f(double walh, int *buffer, int i)
{
    int y;
    int color;

    y = (W_H / 2) +  floor(walh / 2);
    color = convert_color(90, 90, 90);
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
