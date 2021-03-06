/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:40:29 by selhanda          #+#    #+#             */
/*   Updated: 2022/07/05 16:40:32 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	des_b(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
}

void	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
}

void	check_file(char *str)
{
	if (ft_strcmp(&str[ft_strlen(str) - 4], ".cub") != 0)
	{
        ft_putstr("extention error\n");
		exit(1);
	}
}

void	init_file(t_file *file, char *filename)
{
	file->file_line = 0;
    file->file_width = 0;
	file->file_name = filename;
}
