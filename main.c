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

void init_game(t_data *data) // init game
{
	data->player = (t_player *)malloc(sizeof(t_player));
	data->player->player_x = 200;
	data->player->player_y = 100;
	drawPlayer(data->mlx, data->win,
		data->player->player_x, data->player->player_y);
}



int	main(int argc, char **argv)
{
    t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	(void)argc;
	(void)argv;
	
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1024, 512, "cub3d");
	init_game(data);
	mlx_hook(data->win, 2, 1L << 0, move_f, data);
	mlx_hook(data->win, 17, 0L, des_b, data);
	mlx_loop(data->mlx);
}