#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;

	if (dst == NULL && src == NULL)
		return (0);
	size = (size_t) ft_strlen(src);
	if (dstsize == 0)
		return (size);
	while (--dstsize && *src)
		*dst++ = *(char *)src++;
	*dst = 0;
	return (size);
}
