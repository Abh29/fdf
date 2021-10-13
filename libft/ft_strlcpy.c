/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:03 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:36:03 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;

	if (dst == NULL && src == NULL)
		return (0);
	size = (size_t) ft_strlen(src);
	if (dstsize == 0)
		return (size);
	while (--dstsize && *src)
		*dst++ = *(char *)src++;
	*dst = 0;
	return (size);
}
