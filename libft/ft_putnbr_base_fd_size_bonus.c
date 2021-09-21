#include "libft.h"

typedef struct s_putnbr_base_fd_size_bonus
{
	unsigned int		nb;
	const char			*base;
}				t_putnbr_args;

static void	ft_print_nbr_base(t_putnbr_args args, char *buff, \
			int fd, size_t *fsize)
{
	int	i;
	int	size;

	size = ft_strlen(args.base);
	i = 0;
	while (args.nb > 0)
	{
		buff[i++] = args.base[args.nb % size];
		args.nb /= size;
	}
	while (i > 0)
		ft_putchar_fd_size(buff[--i], fd, fsize);
}

void	ft_putnbr_base_fd_size(int nb, const char *base, int fd, size_t *size)
{
	int				base_size;
	t_putnbr_args	args;
	char			*buff;

	if (base == NULL)
		return ;
	args.base = base;
	base_size = ft_strlen(base);
	if (base_size < 2)
		return ;
	if (nb == 0)
	{
		ft_putchar_fd_size('0', fd, size);
		return ;
	}
	if (nb < 0)
		nb = (unsigned)(__UINT32_MAX__ + nb + 1);
	buff = malloc (33);
	if (buff == NULL)
		return ;
	args.nb = (unsigned int)nb;
	ft_print_nbr_base(args, buff, fd, size);
	free(buff);
	return ;
}
