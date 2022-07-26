/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:34:02 by selhanda          #+#    #+#             */
/*   Updated: 2022/06/26 14:34:05 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/cub3d.h"

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
void init_game(t_data *data) // init game
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, W_W, W_H, "cub3d");
	data->player = (t_player *)malloc(sizeof(t_player));
    data->ray = (t_ray *)malloc(sizeof(t_ray));
	data->player->player_x = 40;
	data->player->player_y = 40;
    data->player->pa = degtorad(0);
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
        x = 0;
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
        y = data->player->player_y + (sin(ray->rayangle) * i);
        x = data->player->player_x + (cos(ray->rayangle) * i);
        if (data->map[(int)(y / 32)][(int)(x / 32)] == '1')
            break;
        i++;
    }
    ray->rayx = x;
    ray->rayy = y;
}
void castray(t_data *data)
{   
    t_ray *ray;
    int     i;
    double dist;
    double walh;
    int color;


    ray = data->ray;
    ray->rayangle = data->player->pa - (FOV / 2);
    i = 0;
    rayinit(data, ray->rayangle);
    color = 16777215;
    while(i < W_W)
    {
        if ( i >= 0 && i <= 100)
            color = 15100611;
        else if (i >= 101 && i <= 200)
            color = 16768768;
        find_intersiction(data, ray);
        dist = sqrt(powf(data->player->player_x - ray->rayx, 2.0) + powf(data->player->player_y - ray->rayy, 2.0));
        dist = dist * cos(degtorad(ray->rayangle - data->player->pa));
        walh = ((W_H / 2) / dist);
        draw_line(data, i, 0, i, (W_H / 2)  - (int)walh, 32511);
        draw_line(data, i, (W_H / 2)  - (int)walh, i, (W_H / 2)  + (int)walh, color);
        draw_line(data, i, (W_H / 2)  + (int)walh, i, W_H, 16741888);
        ray->rayangle += (FOV / W_W);
        i++;
     }
}

int main_loop(t_data *cub)
{
    mlx_hook(cub->win, 2, 0, move_f, cub);
    castray(cub);
    return (0);
}

int	main(int argc, char **argv)
{
    int fd;
    t_data *cub;

    if (argc != 2)
        error_1();
    if (argc == 2)
    {
        cub = malloc(sizeof(t_data));
        check_file(argv[1]);
        cub->file = (t_file *)malloc(sizeof(t_file));
        init_file(cub->file, argv[1]);
        fd = open(argv[1], O_RDWR);
        cub->map = malloc_map(fd, cub->file);
        close(fd);
        fd = open(argv[1], O_RDWR);
        cub->map = ft_get_map(fd, cub->map, cub->file);
        init_game(cub);
        mlx_hook(cub->win, 2, 0, move_f, cub);
        mlx_loop_hook(cub->mlx, main_loop, cub);
        mlx_loop(cub->mlx);
    }
}