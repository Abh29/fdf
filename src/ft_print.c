#include "../fdf.h"

void	ft_printmap(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
			printf("%d   ", map->alts[i][j++]);
		printf("\n");
		i++;
	}
}