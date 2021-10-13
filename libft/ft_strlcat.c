/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:35:55 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:35:57 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		size;

	if (dst == NULL && src == NULL)
		return (0);
	size = (size_t) ft_strlen(dst);
	if (size > dstsize)
		size = dstsize;
	size += (size_t) ft_strlen(src);
	if (dstsize == 0)
		return (size);
	while (--dstsize && *dst)
		dst++;
	if (dstsize)
	{
		dstsize++;
		while (--dstsize && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (size);
}
