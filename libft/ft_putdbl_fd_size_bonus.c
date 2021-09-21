#include "libft.h"

typedef struct s_putdbl_fd_size_bonus
{
	int		firstpart;
	int		secondpart;
	double	floatpart;
}				t_putdbl_fd_size_bonus;

static double	ft_pow10(int e)
{
	double	out;

	out = 1;
	if (e < 0)
		while (e++ < 0)
			out /= 10;
	else
		while (e-- > 0)
			out *= 10;
	return (out);
}

static int	ft_intsize(int n)
{
	int	size;

	size = 1;
	while (n / 10 > 0 && size++ > 0)
		n /= 10;
	return (size);
}

static void	ft_onepart(long double dbl, t_options options, \
			t_options ops, t_putdbl_fd_size_bonus vars)
{
	if (!options.l_shift)
	{
		if (options.width > options.precision)
			ops.width -= options.precision;
		if (options.precision != 0 && options.width)
			ops.width--;
		if (options.filler)
			ops.precision = ops.width;
		if (dbl < 0 || options.sign)
			ops.precision--;
		if (vars.firstpart == 0 && options.filler == 0)
			ops.precision = 1;
		options.width = 0;
	}
	else
	{
		ops.width = 0;
		if (vars.firstpart == 0)
		{
			ops.precision = 1;
			options.width--;
		}
		if (options.precision != 0 && options.width)
			options.width--;
	}
}

static t_putdbl_fd_size_bonus	ft_firstpart(long double dbl, \
							t_options options, int *sig_zeros)
{
	long double				d;
	t_putdbl_fd_size_bonus	vars;

	d = dbl;
	if (d < 0)
		d *= -1;
	vars.firstpart = (int)d;
	vars.floatpart = d - (double)vars.firstpart;
	vars.floatpart *= ft_pow10(options.precision);
	vars.secondpart = (int) vars.floatpart;
	*sig_zeros = options.precision - ft_intsize(vars.secondpart);
	vars.floatpart -= vars.secondpart;
	if (vars.floatpart > 0.5)
	{
		vars.secondpart++;
		*sig_zeros = options.precision - ft_intsize(vars.secondpart);
	}
	if (vars.secondpart > ft_pow10(options.precision) - 1)
	{
		vars.firstpart++;
		vars.secondpart = 0;
		*sig_zeros = 0;
	}
	return (vars);
}

void	ft_putdbl_fd_size(long double dbl, int fd, \
		size_t *size, t_options options)
{
	t_putdbl_fd_size_bonus	vars;
	t_options				ops;
	int						sig_zeros;

	vars = ft_firstpart(dbl, options, &sig_zeros);
	if (dbl < 0)
		vars.firstpart *= -1;
	ops = options;
	ops.precision = 0;
	ft_onepart(dbl, options, ops, vars);
	ft_putnbr_fd_size(vars.firstpart, fd, size);
	if (options.precision != 0)
	{
		ft_putchar_fd_size('.', fd, size);
		options.sign = 0;
		if (vars.secondpart != 0)
			options.precision = 0;
		while (sig_zeros--)
			ft_putchar_fd_size('0', fd, size);
		ft_putnbr_fd_size(vars.secondpart, fd, size);
	}
}
