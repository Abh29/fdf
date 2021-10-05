#include "../fdf.h"

typedef struct s_rot
{
	double	cosA;
	double	cosB;
	double	sinA;
	double	sinB;
}				t_rot;

void	ft_rotate_3d(t_point *p, double alpha, double beta)
{
	int		x;
	int		y;
	int		z;
	t_rot	R;

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

void	ft_translate_2d(t_point *p, int tx, int ty)
{
	p->x += tx;
	p->y += ty;
}

void	ft_scale_2d(t_point *p, int scaleX, int scaleY)
{
	p->x *= scaleX;
	p->y *= scaleY;
}
