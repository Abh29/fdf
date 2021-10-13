/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:48 by mehill            #+#    #+#             */
/*   Updated: 2021/10/13 20:36:48 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
int				ft_strlen_(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);

#endif