/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:34:24 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:34:25 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*sdst;
	unsigned char		*ssrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	sdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	while (n--)
		*sdst++ = *ssrc++;
	return (dst);
}
