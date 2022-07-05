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

void init_game(t_data *data) // init game
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->file->file_width * 60, data->file->file_line * 60, "cub3d");
	data->player = (t_player *)malloc(sizeof(t_player));
	data->player->player_x = 100;
	data->player->player_y = 100; 
    data->player->pa = 0.1;
    data->player->pdx = cos(data->player->pa) * 12;
    data->player->pdy = sin(data->player->pa) * 12;
    ft_drwa2dmap(data);
    ft_display(data->player->player_x, data->player->player_y, data, 16711680, 12);
    draw_m_line(data);
}

void    ft_display(int x, int y, t_data *cub, int color, int size)
{

    int i = 0;
    int j = 0;
    int first_val = x;
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
    x = 0;
    y = 0;
    while (cub->map[i])
    {
        j = 0;
        x = 0;
        while (cub->map[i][j])
        {
            if (cub->map[i][j] == '1')
                ft_display(x, y, cub, 45312, 60);
            x += 60;
            j++;
        }
        y += 60;
        i++;
    }
}

void draw_line(t_data *data, float bx, float by, float endx, float endy)
{
    float dx = endx - bx;
    float dy = endy - by;
    int pexels = sqrt((dx * dx) + (dy * dy));

    dx /= pexels;
    dy /= pexels;
    float px = bx;
    float py = by;

    while (pexels)
    {
        mlx_pixel_put(data->mlx, data->win , px, py, 16776960);
        px += dx;
        py += dy;
        --pexels;
    }
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
        mlx_loop(cub->mlx);
    }
}