#include "../fdf.h"

void	ft_exit(char *msg, int err)
{
	ft_putstr_fd(msg, 2);
	exit(err);
}
