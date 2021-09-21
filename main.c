#include "fdf.h"

int main(int argc, char **argv)
{
	t_map map;
	t_point ***points;
	t_transform tsf;
	void	*mlx;
	void	*window;

	

	if (argc < 2)
		ft_exit("Error : more arguments are expected !\n", 1);
	ft_readmap(&map, argv[1]);
	ft_printmap(&map);


	tsf.alpha = 35.264;
	tsf.beta = 45;
	tsf.scaleX = 1;
	tsf.scaleY = 1;
	tsf.scaleZ = 1;

	
	points = ft_pointsmap(&map);
	ft_transform(&map, &tsf, &points);
	printf("this is printing the points  : \n");
	ft_print_pointsmap(&map, &points);
	ft_free_pointsmap(&map, &points);
	mlx = mlx_init();
	if (mlx == NULL)
		ft_exit("Error : Could not initite a window !\n", 1);
	window = mlx_new_window(mlx, 512, 512, "fdf...");
	if (window = NULL)
		ft_exit("Error : Could not create a new window !\n", 1);
	
	for (int i = 0; i < map.rows; i++)
	{
		free(map.alts[i]);
	}
	free(map.alts);
	return (0);
}
