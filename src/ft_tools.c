/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:00:37 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:00:37 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_exit(char *msg, int err)
{
	ft_putstr_fd(msg, 2);
	exit(err);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->alts[i]);
		free(map->colors[i++]);
	}
	free(map->alts);
	free(map->colors);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_init_window(t_mlx *mlx, t_transform *tsf, char *title)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_exit("Error : Could not initite a window !\n", 1);
	mlx->img = mlx_new_image(mlx->mlx, tsf->width + 512, tsf->height + 512);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp), \
	&(mlx->line_length), &(mlx->endian));
	mlx->window = mlx_new_window(mlx->mlx, 1024, 1024, title);
	if (mlx->addr == NULL)
		ft_exit("Error : Could not create a new window !\n", 1);
	mlx_do_key_autorepeaton(mlx->mlx);
}

void	ft_init_data(t_map *map, t_transform *tsf)
{
	tsf->alpha = 30;
	tsf->beta = 30;
	tsf->gama = 160;
	ft_rotation_matrix(tsf);
	tsf->scaleX = ft_max(1, 512 / map->rows);
	tsf->scaleY = ft_max(1, 512 / map->cols);
	tsf->scaleZ = 2;
	tsf->width = ft_max(map->rows, 512);
	tsf->height = ft_max(map->cols, 512);
}
