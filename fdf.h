#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	char	*color;
	int		hide;
}				t_point;

typedef	struct s_map
{
	int		cols;
	int 	rows;
	int		**alts;
}				t_map;

typedef struct s_transform
{
	double	alpha;
	double	beta;
	int		scaleX;
	int		scaleY;
	int		scaleZ;
	int		trsltX;
	int		trsltY;
}				t_transform;


void	ft_exit(char *msg, int err);
void	ft_printmap(t_map *map);
void	ft_readmap(t_map *map, char *file);


void	ft_draw_3d_line(t_point p0, t_point p1, double alpha, double beta);
void	ft_rotate_3d(t_point *p, double alpha, double beta);
void	ft_draw_2d_line(int x0, int y0, int x1, int y1);



void	ft_print_pointsmap(t_map *map, t_point ****points);
void	ft_transform(t_map *map, t_transform *tsf, t_point ****pos);
t_point	***ft_pointsmap(t_map *map);
void	ft_free_pointsmap(t_map *map, t_point ****points);

#endif