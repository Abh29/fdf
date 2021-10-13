/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:33:18 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:33:42 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*save;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	save = *lst;
	while (save->next)
		save = save->next;
	save->next = new;
}
