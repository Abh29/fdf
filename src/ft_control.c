/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:59:54 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:01:11 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_change_translate(int key, t_param *param)
{
	if (key == 65362 || key == 126)
		param->originY++;
	else if (key == 65364 || key == 125)
		param->originY = ft_max(--param->originY, 0);
	else if (key == 65363 || key == 124)
		param->originX++;
	else if (key == 65361 || key == 123)
		param->originX = ft_max(--param->originX, 0);
	else
		return (0);
	return (1);
}

int	ft_change_scale(int key, t_transform *tsf)
{
	if (key == 97 || key == 12)
		tsf->scaleX++;
	else if (key == 113 || key == 0)
		tsf->scaleX--;
	else if (key == 122 || key == 13)
		tsf->scaleY++;
	else if (key == 115 || key == 1)
		tsf->scaleY--;
	else if (key == 101 || key == 14)
		tsf->scaleZ++;
	else if (key == 100 || key == 2)
		tsf->scaleZ--;
	else
		return (0);
	return (1);
}

int	ft_change_rotation(int key, t_transform *tsf)
{
	if (key == 65429 || key == 89)
		tsf->alpha++;
	else if (key == 65430 || key == 86)
		tsf->alpha--;
	else if (key == 65431 || key == 91)
		tsf->beta++;
	else if (key == 65437 || key == 87)
		tsf->beta--;
	else if (key == 65434 || key == 92)
		tsf->gama++;
	else if (key == 65432 || key == 88)
		tsf->gama--;
	else
		return (0);
	ft_rotation_matrix(tsf);
	return (1);
}

int	ft_set_predef_transform(int key, t_transform *tsf, t_map *map)
{
	if (key == 105 || key == 34)
	{
		ft_init_data(map, tsf);
		return (1);
	}
	else if (key == 112 || key == 35)
	{
		tsf->alpha = 0;
		tsf->beta = 0;
		tsf->gama = 0;
		ft_rotation_matrix(tsf);
		tsf->scaleX = ft_max(1, 512 / map->rows);
		tsf->scaleY = ft_max(1, 512 / map->cols);
		tsf->scaleZ = 2;
		tsf->width = ft_max(map->rows, 512);
		tsf->height = ft_max(map->cols, 512);
		return (1);
	}
	return (0);
}

int	ft_close(int keycode, t_param *param)
{
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_image(param->mlx->mlx, param->mlx->img);
		mlx_destroy_window(param->mlx->mlx, param->mlx->window);
		ft_free_map(param->map);
		ft_exit("bye!!!\n", 0);
	}
	return (0);
}
