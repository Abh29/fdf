#include "libft.h"

void	ft_putchar_fd_size(char c, int fd, size_t *size)
{
	write(fd, &c, 1);
	(*size)++;
}
