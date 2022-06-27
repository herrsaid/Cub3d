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
#include "inc/main.h"

int	main(int argc, char **argv)
{
    t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	(void)argc;
	(void)argv;
	
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 500, 500, "cub3d");
	mlx_string_put(data->mlx, data->win, 150, 150, 16777215, "said + khawla = NOLove");
	mlx_loop(data->mlx);
}