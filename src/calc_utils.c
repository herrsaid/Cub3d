/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2022/08/02 16:50:48 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/13 13:38:58 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void rayinit(t_data *data, float rayangle)
{
        data->ray->isfacingdown = 0;
    data->ray->isfacingup = 0;
    data->ray->isfacingright = 0;
    data->ray->isfacingleft = 0;
    if (rayangle > 0 && rayangle < PI)
        data->ray->isfacingdown = 1;
    else
        data->ray->isfacingup = 1;
    if (rayangle < 0.5 * PI || rayangle > 1.5 * PI)
        data->ray->isfacingright = 1;
    else
        data->ray->isfacingleft = 1;

}

void	find_intersiction(t_data *data, t_ray *ray)
{
	int		i;
	float	x;
	float	y;

	i = 1;
	while (1)
	{
		y = data->player->player_y + (sin(ray->rayangle) * i) / 10;
		x = data->player->player_x + (cos(ray->rayangle) * i) / 10;
		if (data->map[(int)(y / 64)][(int)(x / 64)] == '1')
			break ;
		i++;
	}
	ray->rayx = x;
	ray->rayy = y;
}

void	ft_display(int x, int y, t_data *cub, int color, int size)
{
	int	i;
	int	j;
	int	first_val;

	i = 0;
	first_val = x;
	while (i < size)
	{
		x = first_val;
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(cub->mlx, cub->win, x, y, color);
			x++;
			j++;
		}
		y++;
		i++;
	}
}

void	ft_drwa2dmap(t_data *cub)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (cub->map[i])
	{
		j = 0;
		x = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				ft_display(x, y, cub, 16777215, 8);
			x += 8;
			j++;
		}
		y += 8;
		i++;
	}
}

void	calc_wall_h(t_data *data, t_ray *ray)
{
	data->dist = calc_dist(data->player->player_x, ray->rayx, data->player->player_y, ray->rayy);
	data->dist = data->dist * cos(ray->rayangle - data->player->pa);
	data->walh = ((W_H / 2) / data->dist);
	if (data->walh >= 10.657184)
		data->walh = 10.657184;
	data->walh *= 128;
	data->walh = floor(data->walh);
}
