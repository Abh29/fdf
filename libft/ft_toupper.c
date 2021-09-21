#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return ((unsigned char)(c - 32));
	return (c);
}
