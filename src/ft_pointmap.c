#include "../fdf.h"

t_point	***ft_pointsmap(t_map *map)
{
	t_point	***out;
	int		i;
	int		j;

	out = malloc ((map->rows + 1) * sizeof(t_point *));
	if (out == NULL)
		ft_exit("Error : Unable to allocate memory for points map !\n", 1);
	i = 0;
	while (i < map->rows)
	{
		out[i] = malloc((map->cols + 1) * sizeof(t_point *));
		if (out[i] == NULL)
			ft_exit("Error : Unable to allocate memory for points map !\n", 1);
		j = 0;
		while (j < map->cols)
		{
			out[i][j] = malloc(sizeof(t_point));
			if (out[i][j] == NULL)
				ft_exit("Error : Unable to allocate memory for points map !\n", 1);
			j++;
		}
		i++;
	}
	return (out);
}

void	ft_translate(t_map * map, t_transform *tsf, t_point ****pos)
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
			p->x += tsf->trsltX * -1;
			p->y += tsf->trsltY * -1;
			j++;
		}
		i++;
	}
}

void	ft_transform(t_map *map, t_transform *tsf, t_point ****pos)
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
			p->x = i * tsf->scaleX;
			p->y = j * tsf->scaleY;
			p->z = map->alts[i][j] * tsf->scaleZ;
			ft_rotate_3d(p, tsf->alpha, tsf->beta);
			if (tsf->trsltX > p->x)
				tsf->trsltX = p->x;
			if (tsf->trsltY > p->y)
				tsf->trsltY = p->y;
			j++;
		}
		i++;
	}
	//ft_print_pointsmap(map, *pos);
	printf("****************here! %d %d\n\n", tsf->trsltX, tsf->trsltY);
	ft_translate(map, tsf, pos);
}

void	ft_print_pointsmap(t_map *map, t_point ****points)
{
	int	i;
	int j;
	t_point *p;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			p = points[0][i][j];
			printf("(%d, %d)  ", p->x, p->y);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_free_pointsmap(t_map *map, t_point ****points)
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

