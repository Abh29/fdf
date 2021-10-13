/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:00:39 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:04:10 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_rotation_matrix(t_transform *tsf)
{
	double	coss[3];
	double	sins[3];

	coss[0] = cos(tsf->alpha * M_PI / 180);
	coss[1] = cos(tsf->beta * M_PI / 180);
	coss[2] = cos(tsf->gama * M_PI / 180);
	sins[0] = sin(tsf->alpha * M_PI / 180);
	sins[1] = sin(tsf->beta * M_PI / 180);
	sins[2] = sin(tsf->gama * M_PI / 180);
	tsf->R[0][0] = coss[0] * coss[1];
	tsf->R[0][1] = coss[0] * sins[1] * sins[2] - sins[0] * coss[2];
	tsf->R[0][2] = coss[0] * sins[1] * coss[2] + sins[0] * sins[2];
	tsf->R[1][0] = sins[0] * coss[1];
	tsf->R[1][1] = sins[0] * sins[1] * sins[2] + coss[0] * coss[2];
	tsf->R[1][2] = sins[0] * sins[1] * coss[2] - coss[0] * sins[2];
	tsf->R[2][0] = sins[1] * -1;
	tsf->R[2][1] = coss[1] * sins[2];
	tsf->R[2][2] = coss[1] * coss[2];
}

void	ft_rotate_3d(t_point *p, t_transform *tsf)
{
	int		x;
	int		y;
	int		z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x * tsf->R[0][0] + y * tsf->R[0][1] + z * tsf->R[0][2];
	p->y = x * tsf->R[1][0] + y * tsf->R[1][1] + z * tsf->R[1][2];
	p->z = x * tsf->R[2][0] + y * tsf->R[2][1] + z * tsf->R[2][2];
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
