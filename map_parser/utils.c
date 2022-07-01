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