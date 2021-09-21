#include "get_next_line.h"
#include <stdio.h>

static void	ft_add_nl(char **line)
{
	char	*tmp;

	tmp = ft_strjoin(*line, "\n");
	free(*line);
	*line = tmp;
}

static int	ft_handle_rest(char **line, char **rest)
{
	char	*ln;

	if (*rest)
	{
		ln = ft_strchr(*rest, '\n');
		if (ln)
		{
			*ln = 0;
			*line = ft_strdup(*rest);
			ln = ft_strdup(ln + 1);
			free(*rest);
			*rest = NULL;
			if (*ln)
				*rest = ft_strdup(ln);
			free(ln);
			ln = NULL;
			ft_add_nl(line);
			return (1);
		}
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (0);
}

static int	ft_hahdnle_new_read(char *buff, char **line, char **rest)
{
	char	*nl;
	int		out;

	out = 0;
	nl = ft_strchr(buff, '\n');
	if (nl)
	{
		*nl = 0;
		if (*(nl + 1))
			*rest = ft_strdup(nl + 1);
		nl = NULL;
		out = 1;
	}
	if (*line == NULL)
		*line = ft_strdup(buff);
	else
	{
		nl = ft_strdup(*line);
		free(*line);
		*line = NULL;
		*line = ft_strjoin(nl, buff);
		free(nl);
		nl = NULL;
	}
	return (out);
}

static int	ft_part_two(int fd, char **line, char **rest)
{
	char	*buff;
	int		size;

	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (0);
	size = read(fd, buff, BUFFER_SIZE);
	while (size > 0)
	{
		buff[size] = 0;
		if (ft_hahdnle_new_read(buff, line, rest))
		{
			ft_add_nl(line);
			break ;
		}
		size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	buff = NULL;
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*line;

	if (BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (ft_handle_rest(&line, &rest))
		return (line);
	if (ft_part_two(fd, &line, &rest))
		return (line);
	return (NULL);
}
