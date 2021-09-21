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
