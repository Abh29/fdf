#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sdst;
	unsigned char	*ssrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	sdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	if (sdst < ssrc)
		while (len--)
			*sdst++ = *ssrc++;
	else
	{
		sdst += (len - 1);
		ssrc += (len - 1);
		while (len--)
			*sdst-- = *ssrc--;
	}
	return (dst);
}
