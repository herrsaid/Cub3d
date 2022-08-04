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

void init_game(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, W_W, W_H, "cub3d");
	data->player = (t_player *)malloc(sizeof(t_player));
    data->ray = (t_ray *)malloc(sizeof(t_ray));
	data->player->player_x = 64;
	data->player->player_y = 64;
    data->player->pa = degtorad(90);
    data->player->pdx = cos(data->player->pa) * 12;
    data->player->pdy = sin(data->player->pa) * 12;
    castray(data);
}

void castray(t_data *data)
{   
    t_ray *ray;
    int     i;
    void *image;
    int y;

    ray = data->ray;
    ray->rayangle = data->player->pa - (FOV / 2);
    i = 0;
    image = mlx_new_image(data->mlx, W_W, W_H);
    data->xpm_img = mlx_xpm_file_to_image(data->mlx, "./walltxt.xpm", &y, &y);
    data->xpm_pxls = (int *)mlx_get_data_addr(data->xpm_img, &y, &y, &y);
    rayinit(data, ray->rayangle);
    while(i < W_W)
    {
        find_intersiction(data, ray);
        calc_wall_h(data, ray);
        draw_wall(data->walh, i, ray, get_buffer_img(image), data);
        draw_c(data->walh, get_buffer_img(image), i);
        draw_f(data->walh, get_buffer_img(image), i);
        ray->rayangle += (FOV / W_W);
        i++;
     }
     mlx_put_image_to_window(data->mlx, data->win, image, 0, 0);
}

int main_loop(t_data *cub)
{
    mlx_hook(cub->win, 2, 0, move_f, cub);
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