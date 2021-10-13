/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:00:08 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:20:00 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

typedef struct s_draw
{
	int	dx;
	int	dy;
	int	xi;
	int	p;
	int	x;
	int	y;
}				t_draw;

static void	ft_helper1(t_draw *l, t_point p0, t_point p1)
{
	l->dx = p1.x - p0.x;
	l->dy = p1.y - p0.y;
	l->xi = 1;
	if (l->dx < 0)
	{
		l->xi = -1;
		l->dx *= -1;
	}
	l->p = 2 * l->dx - l->dy;
	l->x = p0.x;
	l->y = p0.y;
}

void	ft_plotYLine(t_mlx *img, t_point p0, t_point p1)
{
	t_draw	l;
	int		color;

	ft_helper1(&l, p0, p1);
	while (l.y < p1.y)
	{
		if (l.y < p1.y / 2)
			color = p0.color;
		else
			color = p1.color;
		ft_put_pixel(img, l.x, l.y, color);
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

static void	ft_helper2(t_draw *l, t_point p0, t_point p1)
{
	l->dx = p1.x - p0.x;
	l->dy = p1.y - p0.y;
	l->x = p0.x;
	l->y = p0.y;
	l->p = 2 * l->dy - l->dx;
}

void	ft_plotXLine(t_mlx *img, t_point p0, t_point p1)
{
	t_draw	l;
	int		color;

	ft_helper2(&l, p0, p1);
	while (l.x < p1.x)
	{
		if (l.x < p1.x / 2)
			color = p0.color;
		else
			color = p1.color;
		ft_put_pixel(img, l.x, l.y, color);
		if (l.p >= 0)
		{
			l.y = l.y + 1;
			l.p = l.p + 2 * l.dy - 2 * l.dx;
		}
		else
		{
			l.p = l.p + 2 * l.dy;
		}
		l.x = l.x + 1;
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
