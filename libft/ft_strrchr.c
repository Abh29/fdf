/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:16 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:36:16 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;

	out = 0;
	while (*s)
	{
		if (*s == (char)c)
			out = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (out);
}
