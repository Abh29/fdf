#include "../fdf.h"

static int		ft_char_index(char *str, int c)
{
	int out = 0;
	while (*str)
	{
		if (*str == c)
			return (out);
		out++;
		str++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int size;
	int out;

	if (str == NULL || base == NULL)
		return (0);
	size = ft_strlen(base);
	out = 0;
	if (*str == '0')
		str++;
	if (*str == 'x')
		str++;
	while (*str && ft_strchr(base, *str))
		out = out * size + ft_char_index(base, *str++);
	return (out);
}
