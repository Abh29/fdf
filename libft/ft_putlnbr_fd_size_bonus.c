#include "libft.h"

static int	ft_numsize(long long *n, int fd, size_t *fsize)
{
	int			size;
	long long	save;

	size = 0;
	if (*n < 0)
	{
		*n *= -1;
		write (fd, "-", 1);
		(*fsize)++;
	}
	save = *n;
	while (save && size++ > -1)
		save /= 10;
	return (size);
}

static void	ft_putthis(int fd, char *s, size_t *fsize)
{
	int	i;

	i = ft_strlen(s);
	write (fd, s, i);
	(*fsize) += i;
}

void	ft_putlnbr_fd_size(long long n, int fd, size_t *fsize)
{
	char	s[21];
	int		i;

	if (n == -9223372036854775807)
	{
		write (fd, "-9223372036854775807", 20);
		*fsize += 20;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		(*fsize)++;
	}
	else
	{
		i = ft_numsize(&n, fd, fsize);
		s[i--] = 0;
		while (n)
		{
			s[i--] = n % 10 + '0';
			n /= 10;
		}
		ft_putthis(fd, s, fsize);
	}
}
