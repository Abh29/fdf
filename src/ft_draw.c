#include "../fdf.h"

typedef	struct s_draw
{
	int dx;
	int	dy;
	int	p;
	int x;
	int y;
}				t_draw;

void	ft_put_pixel(t_mlx *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_3d_pixel(t_mlx *img, t_point p, int alpha, int beta)
{
	ft_rotate_3d(&p, alpha, beta);
	ft_put_pixel(img, p.x, p.y, p.color);
}

void	ft_draw_2d_line(t_mlx *img, t_point p0, t_point p1)
{
	t_draw	l;

	l.dx = p1.x - p0.x;
	l.dy = p1.y - p0.y;
	l.x = p0.x;
	l.y = p0.y;
	l.p = 2 * l.dy - l.dx;
	while (l.x < p1.x)
	{
		if (l.p >= 0)
		{
			ft_put_pixel(img, l.x, l.y, 0xffffff);
			l.y = l.y + 1;
			l.p = l.p + 2 * l.dy - 2 * l.dx;
		}
		else
		{
			ft_put_pixel(img, l.x, l.y, 0xffffff);
			l.p = l.p + 2 * l.dy;
		}
		l.x = l.x + 1;
	}
}

void	ft_draw_grid(t_mlx *img, t_point ***grid, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows - 1)
	{
		j = 0;
		while (j < cols - 1)
		{
			ft_draw_2d_line(img, *grid[i][j], *grid[i + 1][j]);
			ft_draw_2d_line(img, *grid[i][j], *grid[i][j + 1]);
			printf("drawing (%d, %d)--(%d, %d)\n", grid[i][j]->x, grid[i][j]->y, grid[i][j + 1]->x, grid[i][j + 1]->y);
			j++;
		}
		i++;
	}
}
