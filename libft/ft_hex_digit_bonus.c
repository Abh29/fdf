#include "libft.h"

char	ft_hex_digit(int nb)
{
	if (nb > 15)
		return (0);
	if (nb >= 0 && nb < 10)
		return ('0' + nb);
	else
		return ('a' + nb - 10);
}
