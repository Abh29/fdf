#include "libft.h"

typedef struct s_putnbr_unsigned_fd_size_bonus
{
	unsigned long	k;
	char			i;
	size_t			j;
	char			*save;
}				t_putnbr_bonus;

static void	ft_putthis(size_t *size, int fd, t_putnbr_bonus args)
{
	while (args.i-- > 0)
	{
		write (fd, args.save, 1);
		(*size)++;
		args.save--;
	}
}

void	ft_putnbr_unsigned_fd_size(int nb, int fd, size_t *size)
{
	t_putnbr_bonus	args;
	char			*buff;

	if (nb >= 0)
		ft_putnbr_fd_size(nb, fd, size);
	else
	{
		buff = (char *)ft_calloc(12, sizeof(char));
		if (buff == NULL)
			return ;
		args.save = buff;
		args.k = __UINT32_MAX__ + nb + 1;
		args.i = 0;
		while (args.k > 0)
		{
			*args.save++ = (char)(args.k % 10 + '0');
			args.i++;
			args.k /= 10;
		}
		args.save--;
		args.j = args.i;
		ft_putthis(size, fd, args);
		args.save = NULL;
		free(buff);
	}
}
