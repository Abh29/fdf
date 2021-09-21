#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*save;

	save = b;
	while (len--)
		*save++ = c;
	return (b);
}
