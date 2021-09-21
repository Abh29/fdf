#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*sdst;
	unsigned char		*ssrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	sdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	while (n--)
		*sdst++ = *ssrc++;
	return (dst);
}
