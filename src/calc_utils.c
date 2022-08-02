/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:50:48 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/02 16:50:52 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float   degtorad(float deg)
{
    return (deg * (PI / 180.0));
}

int iswall(float x, float y, t_data *data)
{
    int posx;
    int posy;

    posx = (int)(x / 32);
    posy = (int)(y / 32);
    if (data->map[posy][posx] == '1')
        return (1);
    return (0);
}

void rayinit(t_data *data, float rayangle)
{
    data->ray->isfacingdown = 0;
    data->ray->isfacingup = 0;
    if (rayangle > 0 && rayangle < PI)
        data->ray->isfacingdown = 1;
    else
        data->ray->isfacingup = 1;
}

void    find_intersiction(t_data *data, t_ray *ray)
{
    int i;
    float x;
    float y;

    i = 1;
    while (1)
    {
        y = data->player->player_y + (sin(ray->rayangle) * i) / 32;
        x = data->player->player_x + (cos(ray->rayangle) * i) / 32;
        if (data->map[(int)(y / 32)][(int)(x / 32)] == '1')
            break;
        i++;
    }
    ray->rayx = x;
    ray->rayy = y;
}

void    ft_display(int x, int y, t_data *cub, int color, int size)
{

    int i;
    int j;
    int first_val;

    i = 0;
    first_val = x;
    while (i < size)
    {
        x = first_val;
        j = 0;
        while (j < size)
        {
            mlx_pixel_put(cub->mlx, cub->win , x, y, color);
            x++;
            j++;
        }
        y++;
        i++;
    }
}

void    ft_drwa2dmap(t_data *cub)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    y = 0;
    while (cub->map[i])
    {
        j = 0;
        x = W_W + 1;
        while (cub->map[i][j])
        {
            if (cub->map[i][j] == '1')
                ft_display(x, y, cub, 16777215, 32);
            x += 32;
            j++;
        }
        y += 32;
        i++;
    }
}

void calc_wall_h(t_data *data, t_ray *ray)
{
    data->dist = calc_dist(data->player->player_x, ray->rayx, data->player->player_y, ray->rayy);
    data->dist = data->dist * cos(ray->rayangle - data->player->pa);
    data->walh = ((W_H / 2) / data->dist);
    data->walh *= 32;
    data->walh = floor(data->walh);
    if (data->walh > W_H)
        data->walh = W_H;
    if (data->walh < 0)
        data->walh = 0;
}