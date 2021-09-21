#include "libft.h"
#include <stdint.h>

void	ft_putptr_fd(void *ptr, int fd)
{
	int			i;
	int			hold;
	int			c;
	uintptr_t	p;

	p = (uintptr_t)ptr;
	ft_putchar_fd('0', fd);
	ft_putchar_fd('x', fd);
	hold = 0;
	i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{
		c = (p >> i) & 0xf;
		if (!hold && c != 0)
			hold = 1;
		if (hold)
			ft_putchar_fd(ft_hex_digit(c), fd);
		i -= 4;
	}
}
