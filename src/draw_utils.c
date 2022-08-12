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
    if (wallbuttom > W_H)
        wallbuttom = W_H;
    while (y < (W_H / 2)  + floor(walh / 2))
    {
        distfromtop = y + (walh / 2) - (W_H / 2);
        yofset = distfromtop * ((float) 64 / walh);
        if (data->ray->walldir == NW)
            color = data->nw[(64 * yofset) + xofset];
        else if (data->ray->walldir == SW)
            color = data->sw[(64 * yofset) + xofset];
        else if (data->ray->walldir == WW)
            color = data->ww[(64 * yofset) + xofset];
        else if (data->ray->walldir == EW)
            color = data->ew[(64 * yofset) + xofset];
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
