/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:41:08 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 13:41:11 by selhanda         ###   ########.fr       */
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
		ft_putstr("Error\ninvalid extension\n");
		exit(1);
	}
}

void	init_file(t_file *file, char *filename)
{
	file->file_line = 0;
	file->file_width = 0;
	file->file_name = filename;
	file->n_player = 0;
}

void	print_error(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}
