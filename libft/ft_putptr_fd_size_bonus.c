/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd_size_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:35:16 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:35:16 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	ft_putptr_fd_size(void *ptr, int fd, size_t *size)
{
	int			i;
	int			hold;
	int			c;
	uintptr_t	p;

	p = (uintptr_t)ptr;
	ft_putstr_fd_size("0x", fd, size);
	if (ptr == NULL)
	{
		ft_putchar_fd_size('0', fd, size);
		return ;
	}
	hold = 0;
	i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{
		c = (p >> i) & 0xf;
		if (!hold && c != 0)
			hold = 1;
		if (hold)
			ft_putchar_fd_size(ft_hex_digit(c), fd, size);
		i -= 4;
	}
}
