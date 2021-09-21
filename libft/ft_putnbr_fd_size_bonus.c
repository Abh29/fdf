#include "libft.h"

static int	ft_numsize(int *n, int fd, size_t *fsize)
{
	int	size;
	int	save;

	size = 0;
	if (*n < 0)
	{
		*n *= -1;
		ft_putchar_fd_size('-', fd, fsize);
	}
	save = *n;
	while (save && size++ > -1)
		save /= 10;
	return (size);
}

static void	ft_handle_null(int n, int fd, size_t *size)
{
	if (n == -2147483648)
	{
		ft_putstr_fd_size("-2147483648", fd, size);
		return ;
	}
	if (n == 0)
	{
		ft_putchar_fd_size('0', fd, size);
	}
}

void	ft_putnbr_fd_size(int n, int fd, size_t *size)
{
	char		s[11];
	size_t		i;

	i = 0;
	if (n == -2147483648 || n == 0)
	{
		ft_handle_null(n, fd, size);
		return ;
	}
	else
	{
		i = ft_numsize(&n, fd, size);
		s[i--] = 0;
		while (n)
		{
			s[i--] = n % 10 + '0';
			n /= 10;
		}
		i = ft_strlen(s);
		*size += i;
		write (fd, s, i);
	}
}
