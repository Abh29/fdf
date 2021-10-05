#include "../fdf.h"

typedef	struct s_draw
{
	int dx;
	int	dy;
	int xi;
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

void	ft_plotLine(t_mlx *img, t_point p0, t_point p1)
{
	t_draw	l;

	l.dx = p1.x - p0.x;
	l.dy = p1.y - p0.y;
	l.xi = 1;
	if (l.dx < 0)
	{
		l.xi = -1;
		l.dx *= -1;
	}
	l.p = 2 * l.dx - l.dy;
	l.x = p0.x;
	l.y = p0.y;
	while (l.y < p1.y)
	{
		ft_put_pixel(img, l.x, l.y, 0xffffff);
		if (l.p > 0)
		{
			l.x = l.x + l.xi;
			l.p = l.p + 2 * (l.dx - l.dy);
		}
		else
			l.p = l.p + 2 * l.dx;
		l.y = l.y + 1;
	}
}

void	ft_plotHLine(t_mlx *img, t_point p0, t_point p1)
{
	int	x0;
	int	x1;

	x0 = p0.x;
	x1 = p1.x;
	if (x0 > x1)
	{
		x0 += x1;
		x1 = x0 - x1;
		x0 = x0 - x1;
	}
	while (x0 <= x1)
	{
		ft_put_pixel(img, x0, p0.y, 0xffffff);
		x0++;
	}
}

void	ft_draw_2d_line(t_mlx *img, t_point p0, t_point p1)
{
	if (p1.y == p0.y)
		ft_plotHLine(img, p0, p1);
	else if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			ft_plotLine(img, p1, p0);
		else
			ft_plotLine(img, p0, p1);
	}
	else
	{
		if (p0.y > p1.y)
			ft_plotLine(img, p1, p0);
		else
			ft_plotLine(img, p0, p1);
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
