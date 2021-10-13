/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:35:51 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:35:52 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	char	*save;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1);
	size += ft_strlen(s2);
	out = malloc(size + 1);
	if (out == NULL)
		return (NULL);
	save = out;
	while (*s1)
		*out++ = *s1++;
	while (*s2)
		*out++ = *s2++;
	*out = '\0';
	return (save);
}
