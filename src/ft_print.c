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

void	ft_print_grid(t_point ***grid, int rows, int cols)
{
	{
	int	i;
	int j;
	t_point *p;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			p = grid[i][j];
			printf("(%d, %d)  ", p->x, p->y);
			j++;
		}
		printf("\n");
		i++;
	}
}
}
