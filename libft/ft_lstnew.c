/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:34:09 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:34:09 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	out = malloc(sizeof(t_list));
	if (out == NULL)
		return (NULL);
	out->content = content;
	out->next = NULL;
	return (out);
}
