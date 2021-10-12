#include "../fdf.h"

int		ft_change_translate(int key, t_param *param)
{
	if (key == 65362)
		param->originY++;
	else if (key == 65364)
		param->originY = ft_max(--param->originY, 0);
	else if (key == 65363)
		param->originX++;
	else if (key == 65361)
		param->originX = ft_max(--param->originX, 0);
	else
		return (0);
	return (1);
}

int		ft_change_scale(int key, t_transform *tsf)
{
	if (key == 97)
		tsf->scaleX++;
	else if (key == 113)
		tsf->scaleX--;
	else if (key == 122)
		tsf->scaleY++;
	else if (key == 115)
		tsf->scaleY--;
	else if (key == 101)
		tsf->scaleZ++;
	else if (key == 100)
		tsf->scaleZ--;
	else
		return (0);
	return (1);
}

int		ft_change_rotation(int key, t_transform *tsf)
{
	if (key == 65429)
		tsf->alpha++;
	else if (key == 65430)
		tsf->alpha--;
	else if (key == 65431)
		tsf->beta++;
	else if (key == 65437)
		tsf->beta--;
	else if (key == 65434)
		tsf->gama++;
	else if (key == 65432)
		tsf->gama--;
	else
		return (0);
	ft_rotation_matrix(tsf);
	return (1);
}

int		ft_set_predef_transform(int key, t_transform *tsf, t_map *map)
{
	if (key == 105)
	{
		ft_init_data(map, tsf);
		return (1);
	}
	else if (key == 112)
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
	if (keycode == 65307)
	{
		mlx_destroy_image(param->mlx->mlx, param->mlx->img);
		mlx_destroy_window(param->mlx->mlx, param->mlx->window);
		ft_free_map(param->map);
		ft_exit("bye!!!\n", 0);
	}
	return (0);	
}
