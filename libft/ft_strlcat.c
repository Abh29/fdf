#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		size;

	if (dst == NULL && src == NULL)
		return (0);
	size = (size_t) ft_strlen(dst);
	if (size > dstsize)
		size = dstsize;
	size += (size_t) ft_strlen(src);
	if (dstsize == 0)
		return (size);
	while (--dstsize && *dst)
		dst++;
	if (dstsize)
	{
		dstsize++;
		while (--dstsize && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (size);
}
