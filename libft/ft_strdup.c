#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	size;

	size = ft_strlen(s1);
	out = (char *)malloc(size + 1);
	if (out != NULL)
	{
		ft_memcpy(out, s1, size);
		out[size] = 0;
	}
	return (out);
}
