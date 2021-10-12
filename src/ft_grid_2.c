#include "../fdf.h"


void	ft_rotate_grid(t_map *map, t_transform *tsf, t_point ****pos)
{
	t_point	*p;
	int		i;
	int		j;

	i = 0;
	tsf->trsltX = 0;
	tsf->trsltY = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			p = pos[0][i][j];
			ft_rotate_3d(p, tsf);
			if (tsf->trsltX > p->x)
				tsf->trsltX = p->x;
			if (tsf->trsltY > p->y)
				tsf->trsltY = p->y;
			j++;
		}
		i++;
	}
}

void	ft_scale_grid(t_map *map, t_transform *tsf, t_point ****pos)
{
	t_point	*p;
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			p = pos[0][i][j];
			p->x = i * tsf->scaleX;
			p->y = j * tsf->scaleY;
			p->z = map->alts[i][j] * tsf->scaleZ;
			j++;
		}
		i++;
	}
}

void	ft_free_grid(t_map *map, t_point ****points)
{
	int i;
	int j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			free(points[0][i][j]);
			j++;
		}
		free(points[0][i]);
		i++;
	}
	free(*points);
	*points = NULL;
}
