/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:00:23 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:32:08 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_helper1(t_map *map, t_point ***out)
{
	t_point	*p;
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		out[i] = malloc((map->cols + 1) * sizeof(t_point *));
		if (out[i] == NULL)
			ft_exit("Error : Unable to allocate memory for points map !\n", 1);
		j = 0;
		while (j < map->cols)
		{
			p = malloc(sizeof(t_point));
			if (p == NULL)
				ft_exit("Error : Unable to allocate a point in the grid !\n", 1);
			p->x = i;
			p->y = j;
			p->z = map->alts[i][j];
			p->color = map->colors[i][j];
			out[i][j] = p;
			j++;
		}
		i++;
	}
}

t_point	***ft_pointsmap(t_map *map)
{
	t_point	***out;

	out = malloc ((map->rows + 1) * sizeof(t_point *));
	if (out == NULL)
		ft_exit("Error : Unable to allocate memory for points map !\n", 1);
	ft_helper1(map, out);
	return (out);
}

void	ft_translate(t_map *map, t_transform *tsf, t_point ****pos)
{
	t_point	*p;
	int		i;
	int		j;

	i = 0;
	tsf->height = map->rows;
	tsf->width = map->cols;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			p = pos[0][i][j];
			p->x += tsf->trsltX * -1 + 1;
			p->y += tsf->trsltY * -1 + 1;
			if (tsf->height < p->x)
				tsf->height = p->x;
			if (tsf->width < p->y)
				tsf->width = p->y;
			j++;
		}
		i++;
	}
}

static void	ft_helper2(t_transform *tsf, t_point *p)
{
	ft_rotate_3d(p, tsf);
	if (tsf->trsltX > p->x)
		tsf->trsltX = p->x;
	if (tsf->trsltY > p->y)
		tsf->trsltY = p->y;
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
			ft_helper2(tsf, p);
			j++;
		}
		i++;
	}
	ft_translate(map, tsf, pos);
}
