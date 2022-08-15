/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:32:41 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 13:32:46 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_wall(int i, t_ray *ray, t_data *data)
{
	int	y;
	int	color;
	int	distfromtop;
	int	xofset;
	int	yofset;

	y = (W_H / 2) - floor(data->walh / 2);
	data->walltop = (W_H / 2) + floor(data->walh / 2);
	if (data->ray->iswallhitvirtical)
		xofset = ((int)data->ray->rayy % 64);
	else if (data->ray->iswallhithorizontal)
		xofset = (int)data->ray->rayx % 64;
	if (y < 0)
		y = 0;
	if (data->walltop > W_H)
		data->walltop = W_H;
	while (y < data->walltop)
	{
		distfromtop = y + (data->walh / 2) - (W_H / 2);
		yofset = distfromtop * ((float) 64 / data->walh);
		if (data->ray->walldir == NW)
			color = data->nw[(64 * yofset) + xofset];
		else if (data->ray->walldir == SW)
			color = data->sw[(64 * yofset) + xofset];
		else if (data->ray->walldir == WW)
			color = data->ww[(64 * yofset) + xofset];
		else if (data->ray->walldir == EW)
			color = data->ew[(64 * yofset) + xofset];
		data->buffer[(W_W * y) + i] = color;
		y++;
	}
}

void	draw_c(double walh, int *buffer, int i, int color)
{
	int	y;

	y = 0;
	while (y < (W_H / 2) - floor(walh / 2))
	{
		buffer[(W_W * y) + i] = color;
		y++;
	}
}

void	draw_f(double walh, int *buffer, int i, int color)
{
	int	y;

	y = (W_H / 2) + floor(walh / 2);
	while (y < W_H)
	{
		buffer[(W_W * y) + i] = color;
		y++;
	}
}
