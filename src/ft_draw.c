#include "../fdf.h"

typedef	struct s_draw
{
	int dx;
	int	dy;
	int	p;
	int x;
	int y;
}				t_draw;

typedef struct s_rot
{
	double	cosA;
	double	cosB;
	double	sinA;
	double	sinB;
}				t_rot;



void	ft_rotate_3d(t_point *p, double alpha, double beta)
{
	int x;
	int y;
	int z;
	t_rot R;

	R.cosA = cos(alpha);
	R.cosB = cos(beta);
	R.sinA = sin(alpha);
	R.sinB = sin(beta);
	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x * R.cosB - z * R.sinB;
	p->y = x * R.sinA * R.sinB + y * R.cosA + z * R.sinA * R.cosB;
	p->z = x * R.cosA * R.sinB - y * R.sinA + z * R.cosA * R.cosB;
}


void	ft_draw_pixel(int x, int y, char *color)
{
	printf("%d %d %s\n", x, y, color);
}

void	ft_draw_3d_pixel(t_point p, char *color, int alpha, int beta)
{
	ft_rotate_3d(&p, alpha, beta);
	ft_draw_pixel(p.x, p.y, p.color);
}

void	ft_draw_2d_line(int x0, int y0, int x1, int y1)
{
	t_draw l;

	l.dx = x1 - x0;
	l.dy = y1 - y0;
	l.x = x0;
	l.y = y0;
	l.p = 2 * l.dy - l.dx;
	while (l.x < x1)
	{
		if (l.p >= 0)
		{
			ft_draw_pixel(l.x, l.y, "color");
			l.y = l.y + 1;
			l.p = l.p + 2 * l.dy - 2 * l.dx;
		}
		else
		{
			ft_draw_pixel(l.x, l.y, "color");
			l.p = l.p + 2 * l.dy;
		}
		l.x = l.x + 1;
	}
}

void	ft_draw_3d_line(t_point p0, t_point p1, double alpha, double beta)
{
	printf("drawing ...");
	ft_rotate_3d(&p0, alpha, beta);
	ft_rotate_3d(&p1, alpha, beta);
	printf(" %d %d , %d %d \n", p0.x, p0.y, p1.x, p1.y);
	ft_draw_2d_line(p0.x, p0.y, p1.x, p1.y);
	printf("end drawing .\n");
}


