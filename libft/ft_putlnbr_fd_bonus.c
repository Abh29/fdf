#include "libft.h"

static int	ft_numsize(long long *n, int fd)
{
	int			size;
	long long	save;

	size = 0;
	if (*n < 0)
	{
		*n *= -1;
		write (fd, "-", 1);
	}
	save = *n;
	while (save && size++ > -1)
		save /= 10;
	return (size);
}

void	ft_putlnbr_fd(long long n, int fd)
{
	char	s[21];
	int		i;

	if (n == -9223372036854775807)
	{
		write (fd, "-9223372036854775807", 20);
	}
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		i = ft_numsize(&n, fd);
		s[i--] = 0;
		while (n)
		{
			s[i--] = n % 10 + '0';
			n /= 10;
		}
		write (fd, s, ft_strlen(s));
	}
}
