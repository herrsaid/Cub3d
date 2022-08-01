/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:39:47 by selhanda          #+#    #+#             */
/*   Updated: 2022/07/05 16:39:50 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_map(char **map, int line, char *error)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_putstr(error);
	exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while ((*p1 != '\0' && *p2 != '\0') && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

void	error_1(void)
{
    ft_putstr("param error\n");
	exit(1);
}

void	ft_putstr(char *err)
{
	while (*err)
	{
		write(1, err, 1);
		err++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t			i;
    unsigned char	*str1;
    unsigned char	*str2;

    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    i = 0;
    if (n == 0)
        return (0);
    while (str1[i] && str2[i] && i < n - 1 && str1[i] == str2[i])
        i++;
    return (str1[i] - str2[i]);
}
