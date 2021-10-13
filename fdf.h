/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:00:50 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:02:35 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		**colors;
}				t_map;

typedef struct s_transform
{
	double	alpha;
	double	beta;
	double	gama;
	double	R[3][3];
	int		scaleX;
	int		scaleY;
	int		scaleZ;
	int		trsltX;
	int		trsltY;
	int		height;
	int		width;
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

typedef struct s_param
{
	t_map		*map;
	t_point		***points;
	t_transform	*tsf;
	t_mlx		*mlx;
	int			originX;
	int			originY;
}				t_param;

void	ft_exit(char *msg, int err);
void	ft_printmap(t_map *map);
void	ft_readmap(t_map *map, char *file);
void	ft_rotate_3d(t_point *p, t_transform *tsf);
void	ft_rotation_matrix(t_transform *tsf);
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
void	ft_rotate_grid(t_map *map, t_transform *tsf, t_point ****pos);
void	ft_free_map(t_map *map);
int		ft_change_scale(int key, t_transform *tsf);
int		ft_change_rotation(int key, t_transform *tsf);
int		ft_max(int a, int b);
int		ft_atoi_base(char *str, char *base);
int		ft_change_translate(int key, t_param *param);
int		ft_set_predef_transform(int key, t_transform *tsf, t_map *map);
void	ft_init_window(t_mlx *mlx, t_transform *tsf, char *title);
void	ft_init_data(t_map *map, t_transform *tsf);
int		ft_close(int keycode, t_param *param);
void	ft_plotXLine(t_mlx *img, t_point p0, t_point p1);
void	ft_plotYLine(t_mlx *img, t_point p0, t_point p1);

#endif