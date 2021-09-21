#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*root;

	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		ft_lstadd_front(&root, tmp);
		lst = lst->next;
	}
	return (root);
}
