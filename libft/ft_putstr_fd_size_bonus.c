/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_size_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:35:19 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:35:20 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd_size(char *s, int fd, size_t *size)
{
	size_t	i;

	if (s == NULL)
	{
		write (fd, "(null)", 6);
		*size += 6;
		return ;
	}
	i = ft_strlen(s);
	write (fd, s, i);
	(*size) += i;
}
