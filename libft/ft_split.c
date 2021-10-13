/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:35:25 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:35:25 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordcount(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count++;
			s++;
		}
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static	void	ft_helper(char **out, char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			i = 0;
			while (*s && *s != c && i++ > -1)
				s++;
			out[w] = malloc(i + 1);
			s -= i;
			i = 0;
			while (*s && *s != c)
				out[w][i++] = *s++;
			out[w++][i] = '\0';
		}
	}
	out[w] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**out;

	if (s == NULL)
		return (NULL);
	out = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (out == NULL)
		return (NULL);
	ft_helper(out, s, c);
	return (out);
}
