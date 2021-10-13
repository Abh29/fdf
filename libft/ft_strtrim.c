/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:18 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:36:19 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_containchar(const char *s, char c)
{
	while (*s)
		if (c == (char)*s++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	size = ft_strlen(s1);
	if (ft_strlen(set) == 0 || size == 0)
		return (ft_strdup((char *)s1));
	start = 0;
	while (ft_containchar(set, s1[start]))
		start++;
	while (start < size && ft_containchar(set, s1[size - 1]))
		size--;
	if (start < size)
		return (ft_substr((char *)s1, start, size - start));
	return (ft_strdup(""));
}
