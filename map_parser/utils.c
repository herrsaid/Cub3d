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
	perror("error\n");
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