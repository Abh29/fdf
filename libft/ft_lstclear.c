/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:33:23 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:33:41 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		p = *lst;
		*lst = (*lst)->next;
		del(p->content);
		free(p);
	}
	free(*lst);
}
