/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:00:02 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:19:50 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_put_pixel(t_mlx *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_grid(t_mlx *img, t_point ***grid, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (i < rows - 1)
				ft_draw_2d_line(img, *grid[i][j], *grid[i + 1][j]);
			if (j < cols - 1)
				ft_draw_2d_line(img, *grid[i][j], *grid[i][j + 1]);
			j++;
		}
		i++;
	}
}

void	ft_draw_2d_line(t_mlx *img, t_point p0, t_point p1)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			ft_plotXLine(img, p1, p0);
		else
			ft_plotXLine(img, p0, p1);
	}
	else
	{
		if (p0.y > p1.y)
			ft_plotYLine(img, p1, p0);
		else
			ft_plotYLine(img, p0, p1);
	}
}
