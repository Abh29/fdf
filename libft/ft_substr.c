/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:22 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:36:23 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	if (s == NULL)
		return (NULL);
	while (*s && start--)
		s++;
	if (*s == '\0' || len == 0)
		return (ft_strdup(""));
	i = ft_strlen(s);
	if (len > i)
		len = i;
	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (*s && len--)
		out[i++] = *s++;
	out[i] = '\0';
	return (out);
}
