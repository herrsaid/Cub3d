/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:29:15 by salamane          #+#    #+#             */
/*   Updated: 2022/08/29 14:29:19 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_sides(char **map, int x, int y)
{
	if ((int)ft_strlen(map[y]) >= (x + 1))
	{
		if (map[y][x + 1] == '0')
			return (0);
	}
	if (x > 0)
	{
		if (map[y][x - 1] == '0')
			return (0);
	}
	if (check_down(map, y, x) == 0)
		return (0);
	if (check_top(map, y, x) == 0)
		return (0);
	return (1);
}

int	ft_check_zero(char **map, int y, int x, t_data *data)
{
	if (y == 0)
		return (1);
	if (data->file->file_line - 1 == y)
		return (1);
	if ((y - 1) != 0 && ((int)ft_strlen(map[y - 1]) - 1) <= x)
		return (0);
	if ((y + 1) && ((int)ft_strlen(map[y + 1]) - 1) <= x)
	{
		return (0);
	}
	return (1);
}

void	ft_line(t_data *data, char ***map, int *y)
{
	*map = data->map;
	*y = 0;
}

int	check_close(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	ft_line(data, &map, &y);
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (map[y][x] == '0')
			{
				if (ft_check_zero(map, y, x, data) == 0)
					return (0);
			}
			else if (map[y][x] == ' ')
			{
				if (!check_sides(map, x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
