/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:34:39 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:34:39 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_putdbl_fd_bonus
{
	int		correctpart;
	int		intpart;
	double	floatpart;
}				t_putdbl_fd_bonus;

static void	ft_add_one(char *str, int idx)
{
	while (str[idx] == '9')
	{
		str[idx] = '0';
		idx--;
	}
	if (str[idx] == '.')
		idx--;
	str[idx]++;
}

static void	ft_partone(char *out, size_t precision, t_putdbl_fd_bonus vars)
{
	size_t	j;
	int		idx;

	j = 0;
	idx = 2;
	while (vars.floatpart != 0 && j < precision)
	{
		out[idx++] = vars.intpart + '0';
		vars.floatpart = vars.floatpart - ((double)vars.intpart);
		vars.floatpart *= 10;
		vars.intpart = (int)(vars.floatpart);
		j++;
	}
	while (j < precision)
	{
		out[idx++] = '0';
		vars.intpart = 0;
		j++;
	}
	if (vars.intpart > 5)
		ft_add_one(out, idx - 1);
}

static void	ft_putlast(char *out, size_t precision, int fd, int correctpart)
{
	int	idx;

	if (out[0] == '1')
		correctpart++;
	ft_putnbr_fd(correctpart, fd);
	if (precision != 0)
		ft_putchar_fd('.', fd);
	idx = 1;
	while (out[idx++])
		ft_putchar_fd(out[idx], fd);
}

void	ft_putdbl_fd(float f, int fd, size_t precision)
{
	t_putdbl_fd_bonus	vars;
	char				*out;
	int					idx;

	out = (char *)calloc(100, sizeof(char));
	if (out == NULL)
		return ;
	vars.correctpart = (int)f;
	vars.floatpart = f - ((double)vars.correctpart);
	out[0] = '0';
	idx = 1;
	out[idx++] = '.';
	vars.floatpart *= 10;
	vars.intpart = (int)(vars.floatpart);
	ft_partone(out, precision, vars);
	ft_putlast(out, precision, fd, vars.correctpart);
}
