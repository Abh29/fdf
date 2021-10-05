#include "fdf.h"

void	ft_init_window(t_mlx *mlx, int width, int height, char *title)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_exit("Error : Could not initite a window !\n", 1);
	mlx->img = mlx_new_image(mlx->mlx, width, height);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp), \
	&(mlx->line_length), &(mlx->endian));
	mlx->window = mlx_new_window(mlx->mlx, width, height, title);
	if (mlx->addr == NULL)
		ft_exit("Error : Could not create a new window !\n", 1);
}

void	ft_init_data(t_transform *tsf)
{
	tsf->alpha = 35.264;
	tsf->beta = 45;
	tsf->scaleX = 30;
	tsf->scaleY = 30;
	tsf->scaleZ = 30;
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_point		***points;
	t_transform	tsf;
	t_mlx		mlx;
	t_point a,b;

	a.x = 100; a.y = 10; a.z = 10;
	b.x = 200; b.y = 11; b.z = 10;
	ft_init_window(&mlx, 512, 512, "fdf...");
	ft_init_data(&tsf);
	if (argc < 2)
		ft_exit("Error : more arguments are expected !\n", 1);
	ft_readmap(&map, argv[1]);
	points = ft_pointsmap(&map);
	ft_scale_grid(&map, &tsf, &points);
	ft_print_grid(points, map.rows, map.cols);
	//ft_transform(&map, &tsf, &points);
	ft_draw_grid(&mlx, points, map.rows, map.cols);
	//ft_draw_2d_line(&mlx, a, b);
	ft_free_grid(&map, &points);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
