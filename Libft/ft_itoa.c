/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:57:58 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 15:58:11 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 1;
	while (!(n >= 0 && n <= 9))
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_str_alloc(int is_negative, int size, int n)
{
	char	*str;
	int		i;
	int		temp;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	temp = size;
	str[temp] = '\0';
	i = 0;
	while (i < size)
	{
		str[--temp] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int	size;
	int	is_negative;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_len(n);
	is_negative = 0;
	if (n < 0)
	{
		n *= -1;
		is_negative = 1;
	}
	return (ft_str_alloc(is_negative, size, n));
}
