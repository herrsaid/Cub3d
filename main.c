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
	data->player = (t_player *)malloc(sizeof(t_player));
	data->player->player_x = 200;
	data->player->player_y = 100;
    ft_display(data->player->player_x, data->player->player_y, data);
}

void    ft_display(int x, int y, t_data *cub)
{

    int i = 0;
    int j = 0;
    int first_val = x;
    int y_d = y * 2;
    int x_d = x * 2;
    while (i < 20)
    {
        x = first_val;
        j = 0;
        while (j < 20)
        {
            mlx_pixel_put(cub->mlx, cub->win , x, y, 3252244);
            x++;
            j++;
        }
        y++;
        i++;
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
        cub->mlx = mlx_init();
        cub->win = mlx_new_window(cub->mlx, 1200, 512, "cub3d");
        init_game(cub);
        mlx_hook(cub->win, 2, 1L << 0, move_f, cub);
        mlx_loop(cub->mlx);
    }
}