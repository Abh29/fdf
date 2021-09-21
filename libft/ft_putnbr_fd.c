#include "libft.h"

static int	ft_numsize(int *n, int fd)
{
	int	size;
	int	save;

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

void	ft_putnbr_fd(int n, int fd)
{
	char	s[11];
	int		i;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
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
