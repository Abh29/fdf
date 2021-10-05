#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		hide;
}				t_point;

typedef struct s_map
{
	int		cols;
	int		rows;
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

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_mlx;

void	ft_exit(char *msg, int err);
void	ft_printmap(t_map *map);
void	ft_readmap(t_map *map, char *file);
void	ft_rotate_3d(t_point *p, double alpha, double beta);
void	ft_scale_2d(t_point *p, int scaleX, int scaleY);
void	ft_translate_2d(t_point *p, int tx, int ty);
void	ft_draw_2d_line(t_mlx *img, t_point p0, t_point p1);
void	ft_print_pointsmap(t_map *map, t_point ****points);
void	ft_transform(t_map *map, t_transform *tsf, t_point ****pos);
t_point	***ft_pointsmap(t_map *map);
void	ft_free_grid(t_map *map, t_point ****points);
void	ft_put_pixel(t_mlx *img, int x, int y, int color);
void	ft_draw_grid(t_mlx *img, t_point ***grid, int rows, int cols);
void	ft_print_grid(t_point ***grid, int rows, int cols);
void	ft_scale_grid(t_map *map, t_transform *tsf, t_point ****pos);

#endif