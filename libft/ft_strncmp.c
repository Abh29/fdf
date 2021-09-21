#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	while (n--)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 > c2)
			return (1);
		if (c1 < c2)
			return (-1);
		if (c1 == '\0' || c2 == '\0')
			break ;
	}
	return (c1 - c2);
}
