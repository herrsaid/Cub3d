/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_for_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2022/08/13 13:43:33 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/13 13:43:37 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float	degtorad(float deg)
{
	return (deg * (PI / 180.0));
}

float	normalizeangle(float angle)
{
	if (angle < 0)
		angle = (2 * PI) + angle;
	else if (angle > (2 * PI))
		angle = angle - (2 * PI);
	return (angle);
}
