/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:00:26 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:13:13 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_get_cols(t_map *map, int fd)
{
	char	*line;
	char	**spt;
	int		i;

	map->cols = 0;
	map->rows = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return ;
	map->rows++;
	spt = ft_split(line, ' ');
	free(line);
	i = 0;
	while (spt[i])
		free(spt[i++]);
	map->cols = i - 1;
	free(spt);
}

void	ft_map_size(t_map *map, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("Error : Unable to read file !\n", 1);
	ft_get_cols(map, fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->rows++;
		free(line);
	}
	close(fd);
	return ;
}

void	ft_parce_ints(char	**ints, int *arr, int *colors)
{
	int		i;
	char	*s;

	i = 0;
	while (ints[i])
	{
		arr[i] = ft_atoi(ints[i]);
		s = ft_strchr(ints[i], ',');
		if (s)
			colors[i] = ft_atoi_base(s + 1, "0123456789ABCDEF");
		else
			colors[i] = 0xffffff;
		free(ints[i]);
		i++;
	}
}

static	void	ft_helper(t_map *map, char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		ft_exit("Error : Unable to read file !\n", 1);
	map->alts = malloc((map->rows + 1) * sizeof(int *));
	map->colors = malloc((map->rows + 1) * sizeof(int *));
	if (map->alts == NULL || map->colors == NULL)
		ft_exit("Error : Unable to allocate memory for the map !\n", 1);
}

void	ft_readmap(t_map *map, char *file)
{
	char	*line;
	char	**zs;
	int		fd;
	int		i;

	ft_map_size(map, file);
	ft_helper(map, file, &fd);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || *line == '\n')
			break ;
		map->alts[i] = malloc((map->cols + 1) * sizeof(int));
		map->colors[i] = malloc((map->cols + 1) * sizeof(int));
		if (map->alts[i] == NULL || map->colors[i] == NULL)
			ft_exit("Error : Unable to allocate memory for the map !\n", 1);
		zs = ft_split(line, ' ');
		ft_parce_ints(zs, map->alts[i], map->colors[i]);
		free(line);
		free(zs);
		i++;
	}
	close(fd);
}
