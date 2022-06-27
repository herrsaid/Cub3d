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
    void    *mlx;
    void    *win;

	(void)argc;
	(void)argv;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "cub3d");
	mlx_string_put(mlx, win, 150, 150, 16777215, "said + khawla = NOLove");
	mlx_loop(mlx);
}