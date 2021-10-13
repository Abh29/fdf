/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:00:45 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:00:46 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_hook(int key, t_param *param)
{
	t_point		***points;

	if (ft_change_rotation(key, param->tsf) || \
		ft_change_scale(key, param->tsf) || \
		ft_change_translate(key, param) || \
		ft_set_predef_transform(key, param->tsf, param->map))
	{
		points = ft_pointsmap(param->map);
		ft_scale_grid(param->map, param->tsf, &points);
		ft_transform(param->map, param->tsf, &points);
		mlx_destroy_image(param->mlx->mlx, param->mlx->img);
		param->mlx->img = mlx_new_image(param->mlx->mlx, \
		param->tsf->width + 512, param->tsf->height + 512);
		param->mlx->addr = mlx_get_data_addr(param->mlx->img, \
		&(param->mlx->bpp), \
		&(param->mlx->line_length), &(param->mlx->endian));
		ft_draw_grid(param->mlx, points, param->map->rows, param->map->cols);
		mlx_put_image_to_window(param->mlx->mlx, param->mlx->window, \
		param->mlx->img, param->originX, param->originY);
		ft_free_grid(param->map, &points);
	}
	return (0);
}

void	ft_helper(t_param *param, t_map *map, t_transform *tsf, \
t_mlx *mlx)
{
	param->map = map;
	param->tsf = tsf;
	param->mlx = mlx;
	param->originX = 0;
	param->originY = 0;
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_point		***points;
	t_transform	tsf;
	t_mlx		mlx;
	t_param		param;

	ft_helper(&param, &map, &tsf, &mlx);
	if (argc < 2)
		ft_exit("Error : more arguments are expected !\n", 1);
	ft_readmap(&map, argv[1]);
	ft_init_data(&map, &tsf);
	points = ft_pointsmap(&map);
	param.points = points;
	ft_init_window(&mlx, &tsf, "fdf...");
	mlx_hook(mlx.window, 2, 1L << 0, ft_close, &param);
	ft_scale_grid(&map, &tsf, &points);
	ft_transform(&map, &tsf, &points);
	ft_draw_grid(&mlx, points, map.rows, map.cols);
	ft_free_grid(&map, &points);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img, 0, 0);
	mlx_key_hook(mlx.window, &ft_hook, &param);
	mlx_loop(mlx.mlx);
	return (0);
}
