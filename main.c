/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:19:58 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 13:20:02 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	wallhitinit(t_data *data)
{
	int	x;
	int	y;

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

void	setwalldir(t_data *data)
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

void	castray(t_data *data)
{
	t_ray	*ray;
	int		i;

	ray = data->ray;
	data->player->pa = normalizeangle(data->player->pa);
	ray->rayangle = normalizeangle(data->player->pa - (FOV / 2));
	i = 0;
	while (i < W_W)
	{
		ray->rayangle = normalizeangle(ray->rayangle);
		rayinit(data, ray->rayangle);
		find_intersiction(data, ray);
		wallhitinit(data);
		setwalldir(data);
		calc_wall_h(data, ray);
		draw_c(data->walh, data->buffer, i, data->ccolor);
		draw_f(data->walh, data->buffer, i, data->fcolor);
		draw_wall(i, ray, data);
		ray->rayangle += (FOV / W_W);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}

int	main_loop(t_data *cub)
{
	mlx_hook(cub->win, 2, 0, move_f, cub);
	mlx_hook(cub->win, 3, 0, move_r, cub);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*cub;

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
		mlx_loop_hook(cub->mlx, main_loop, cub);
		mlx_hook(cub->win, 17, 0L, des_b, cub->mlx);
		mlx_loop(cub->mlx);
	}
}
