#include "libft.h"

int	ft_memcmp(void *s1, const void *s2, size_t n)
{
	unsigned char		*ss1;
	unsigned char		*ss2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
	}
	return (0);
}
