/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:35:39 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:35:41 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	size;

	size = ft_strlen(s1);
	out = (char *)malloc(size + 1);
	if (out != NULL)
	{
		ft_memcpy(out, s1, size);
		out[size] = 0;
	}
	return (out);
}
