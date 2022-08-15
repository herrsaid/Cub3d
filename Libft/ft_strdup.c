/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:58:39 by selhanda          #+#    #+#             */
/*   Updated: 2022/08/15 15:58:41 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
