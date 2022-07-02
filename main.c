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
	data->player->player_x = 0;
	data->player->player_y = 0;
    ft_drwa2dmap(data);
    ft_display(data->player->player_x, data->player->player_y, data, 16711680, 12);
}

void    ft_display(int x, int y, t_data *cub, int color, int size)
{

    int i = 0;
    int j = 0;
    int first_val = x;
    while (i < size)
    {
        x = first_val;
        j = 0;
        while (j < size)
        {
            mlx_pixel_put(cub->mlx, cub->win , x, y, color);
            x++;
            j++;
        }
        y++;
        i++;
    }
}
void    ft_drwa2dmap(t_data *cub)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    while (cub->map[i])
    {
        j = 0;
        x = 0;
        while (cub->map[i][j])
        {
            if (cub->map[i][j] == '1')
                ft_display(x, y, cub, 45312, 60);
            x += 60;
            j++;
        }
        y += 60;
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
        cub->win = mlx_new_window(cub->mlx, cub->file->file_width * 60, cub->file->file_line * 60, "cub3d");
        printf("%d\n", cub->file->file_width);
        init_game(cub);
        mlx_hook(cub->win, 2, 1L << 0, move_f, cub);
        mlx_loop(cub->mlx);
    }
}