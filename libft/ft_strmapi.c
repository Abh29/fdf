#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	out = malloc(ft_strlen(s) + 1);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
