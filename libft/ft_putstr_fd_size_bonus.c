#include "libft.h"

void	ft_putstr_fd_size(char *s, int fd, size_t *size)
{
	size_t	i;

	if (s == NULL)
	{
		write (fd, "(null)", 6);
		*size += 6;
		return ;
	}
	i = ft_strlen(s);
	write (fd, s, i);
	(*size) += i;
}
