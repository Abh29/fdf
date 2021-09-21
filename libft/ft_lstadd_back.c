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
