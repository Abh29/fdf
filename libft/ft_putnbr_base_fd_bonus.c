#include "libft.h"

static void	ft_print_nbr_base(unsigned int nb, const char *base, \
			char *buff, int fd)
{
	int	i;
	int	size;

	size = ft_strlen(base);
	i = 0;
	while (nb > 0)
	{
		buff[i++] = base[nb % size];
		nb /= size;
	}
	while (i >= 0)
		write (fd, &buff[i--], 1);
}

void	ft_putnbr_base_fd(int nb, const char *base, int fd)
{
	int		base_size;
	char	*out;

	if (base == NULL)
		return ;
	base_size = ft_strlen(base);
	if (base_size < 2)
		return ;
	if (nb == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (nb < 0)
		nb = (unsigned)(__UINT32_MAX__ + nb + 1);
	out = malloc (33);
	if (out == NULL)
		return ;
	ft_print_nbr_base((unsigned int)nb, base, out, fd);
	free(out);
	return ;
}
