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
    check_if_info_file(data);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, W_W, W_H, "cub3d");
	data->player = (t_player *)malloc(sizeof(t_player));
    data->ray = (t_ray *)malloc(sizeof(t_ray));
	data->player->player_x = 70;
	data->player->player_y = 70;
    data->player->pa = degtorad(90);
    data->player->pdx = cos(data->player->pa) * 12;
    data->player->pdy = sin(data->player->pa) * 12;
    data->ccolor = get_color(data->file->config->C);
    data->fcolor = get_color(data->file->config->F);
    castray(data);
}

void castray(t_data *data)
{   
    t_ray *ray;
    int     i;
    void *image;
    int y;
    int *buffer;

    ray = data->ray;
    ray->rayangle = data->player->pa - (FOV / 2);
    i = 0;
    image = mlx_new_image(data->mlx, W_W, W_H);
    data->xpm_img = mlx_xpm_file_to_image(data->mlx, data->file->config->NO, &y, &y);
    data->xpm_pxls = (int *)mlx_get_data_addr(data->xpm_img, &y, &y, &y);
    rayinit(data, ray->rayangle);
    buffer = get_buffer_img(image);
    while(i < W_W)
    {
        find_intersiction(data, ray);
        calc_wall_h(data, ray);
        draw_wall(data->walh, i, ray, buffer, data);
        draw_c(data->walh, buffer, i, data->ccolor);
        draw_f(data->walh, buffer, i, data->fcolor);
        ray->rayangle += (FOV / W_W);
        i++;
     }
     mlx_put_image_to_window(data->mlx, data->win, image, 0, 0);
}

int main_loop(t_data *cub)
{
    //castray(cub);
    mlx_hook(cub->win, 2, 0, move_f, cub);
    return (0);
}

void check_if_info_file(t_data *data)
{
    if (data->file->config->C == NULL)
    {
        printf("no color for ciel\n");
        exit(1);
    }
    if (data->file->config->F == NULL)
    {
        printf("no color for floor\n");
        exit(1);
    }
    if (data->file->config->EA == NULL)
    {
        printf("no EA path\n");
        exit(1);
    }
    if (data->file->config->NO == NULL)
    {
        printf("no NO path\n");
        exit(1);
    }
    if (data->file->config->SO == NULL)
    {
        printf("no SO path\n");
        exit(1);
    }
    if (data->file->config->WE == NULL)
    {
        printf("no WE path\n");
        exit(1);
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
        cub->map = malloc_map(fd, cub->file, cub);
        close(fd);
        fd = open(argv[1], O_RDWR);
        cub->map = ft_get_map(fd, cub->map, cub->file);
        init_game(cub);
        mlx_hook(cub->win, 2, 0, move_f, cub);
        mlx_loop_hook(cub->mlx, main_loop, cub);
        mlx_loop(cub->mlx);
    }
}

int get_color(char *line)
{
    int r;
    int g;
    int b;
    int camma;

    camma = -1;
    while(*line && *line != '\n')
    {
        if (camma == -1)
        {
            r = ft_atoi(line);
            camma = 0;
        }
        if ((ft_isdigit(*line) || *line == ',') && camma <= 2)
		{
			if (*line == ',')
			{
				if (camma == 0)
                     g = ft_atoi((line + 1));
                else if (camma == 1)
                     b = ft_atoi((line + 1));
				camma++;
			}
            
			line++;
		}

    }
    return (convert_color(r, g, b));
}