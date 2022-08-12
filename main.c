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


void init_images(t_data *data)
{
    int fd1;
    int fd2;
    int fd3;
    int fd4;
    data->file->config->NO = ft_substr(data->file->config->NO, 0, ft_strlen(data->file->config->NO) - 1);
    data->file->config->SO = ft_substr(data->file->config->SO, 0, ft_strlen(data->file->config->SO) - 1);
    data->file->config->WE = ft_substr(data->file->config->WE, 0, ft_strlen(data->file->config->WE) - 1);
    data->file->config->EA = ft_substr(data->file->config->EA, 0, ft_strlen(data->file->config->EA) - 1);
    fd1 = open(data->file->config->NO, O_RDONLY);
    fd2 = open(data->file->config->SO, O_RDONLY);
    fd3 = open(data->file->config->WE, O_RDONLY);
    fd4 = open(data->file->config->EA, O_RDONLY);
    if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
    {
        printf("Error\n please check the path of the images\n");
        exit(1);
    }
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
}

void make_image(t_data *data)
{
    int y;
    void *wwimage;
    void *ewimage;
    void *swimage;
    void *nwimage;
    
    wwimage = mlx_xpm_file_to_image(data->mlx, data->file->config->WE, &y, &y);
    ewimage = mlx_xpm_file_to_image(data->mlx, data->file->config->EA, &y, &y);
    swimage = mlx_xpm_file_to_image(data->mlx, data->file->config->SO, &y, &y);
    nwimage = mlx_xpm_file_to_image(data->mlx, data->file->config->NO, &y, &y);
    data->ww = (int *)mlx_get_data_addr(wwimage, &y, &y, &y);
    data->ew = (int *)mlx_get_data_addr(ewimage, &y, &y, &y);
    data->sw = (int *)mlx_get_data_addr(swimage, &y, &y, &y);
    data->nw = (int *)mlx_get_data_addr(nwimage, &y, &y, &y);
}

void init_game(t_data *data)
{
    data->ccolor = get_color(data->file->config->C);
    data->fcolor = get_color(data->file->config->F);
	data->player = (t_player *)malloc(sizeof(t_player));
    data->ray = (t_ray *)malloc(sizeof(t_ray));
    data->player->pa = degtorad(90);
    if (!ft_check_map(data))
    {
        printf("error in the map file\n");
        exit(1);
    }
    init_images(data);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, W_W, W_H, "cub3d");
    make_image(data);
    data->image = mlx_new_image(data->mlx, W_W, W_H);
    data->buffer = get_buffer_img(data->image);
    castray(data);
}

void    wallhitinit(t_data *data)
{
    int x;
    int y;

    x = (int)data->ray->rayx % 64;
    y = (int)data->ray->rayy % 64;
    if (x == 0 || x == 63)
    {
        data->ray->iswallhitvirtical = 1;
        data->ray->iswallhithorizontal = 0;
    }
    else
    {
        data->ray->iswallhithorizontal = 1;
        data->ray->iswallhitvirtical = 0;
    }
}

void    setwalldir(t_data *data)
{
    data->ray->walldir = 0;
    if (data->ray->isfacingleft && data->ray->iswallhitvirtical)
        data->ray->walldir = WW;
    else if (data->ray->isfacingright && data->ray->iswallhitvirtical)
        data->ray->walldir = EW;
    else if (data->ray->isfacingdown && data->ray->iswallhithorizontal)
        data->ray->walldir = SW;
    else if (data->ray->isfacingup && data->ray->iswallhithorizontal)
        data->ray->walldir = NW;
}

float   normalizeAngle(float angle)
{
    if (angle < 0)
        angle = (2 * PI) + angle;
    else if (angle > (2 * PI))
        angle = angle - (2 * PI);
    return (angle);
}

void castray(t_data *data)
{   
    t_ray *ray;
    int     i;

    ray = data->ray;
    data->player->pa = normalizeAngle(data->player->pa);
    ray->rayangle = normalizeAngle(data->player->pa - (FOV / 2));
    i = 0;
    while(i < W_W)
    {
        ray->rayangle = normalizeAngle(ray->rayangle);
        rayinit(data, ray->rayangle);
        find_intersiction(data, ray);
        wallhitinit(data);
        setwalldir(data);
        calc_wall_h(data, ray);
        draw_c(data->walh, data->buffer, i, data->ccolor);
        draw_f(data->walh, data->buffer, i, data->fcolor);
        draw_wall(data->walh, i, ray, data->buffer, data);
        ray->rayangle += (FOV / W_W);
        i++;
     }
     mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}

int main_loop(t_data *cub)
{
    //castray(cub);
    mlx_hook(cub->win, 2, 0, move_f, cub);
    return (0);
}

void check_if_info_file(t_data *data)
{
    if (data->file->config->NO == NULL)
    {
        printf("Error\nno NO path\n");
        exit(1);
    }
    if (data->file->config->SO == NULL)
    {
        printf("Error\nno SO path\n");
        exit(1);
    }
    if (data->file->config->WE == NULL)
    {
        printf("Error\nno WE path\n");
        exit(1);
    }
    if (data->file->config->EA == NULL)
    {
        printf("Error\nno EA path\n");
        exit(1);
    }
    if (data->file->config->F == NULL)
    {
        printf("Error\nno color for floor\n");
        exit(1);
    }
    if (data->file->config->C == NULL)
    {
        printf("Error\nno color for ciel\n");
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
        check_if_info_file(cub);
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
        if (*line == '-')
        {
            printf("Error: Invalid color range\n");
            exit(1);
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
    if (r > 255 || g > 255 || b > 255)
    {
        printf("Error: Invalid color range\n");
        exit(1);
    }
    return (convert_color(r, g, b));
}