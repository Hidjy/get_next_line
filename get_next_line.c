/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 21:31:54 by laime             #+#    #+#             */
/*   Updated: 2015/01/15 18:08:37 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*mem = NULL;
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;
	char		*chr;

	if (fd <= 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	if (mem != NULL)
	{
		chr = ft_strchr(mem, '\n');
		if (chr != NULL)
		{
			tmp = mem;
			*line = ft_strsub(mem, 0, chr - mem);
			mem = ft_strsub(mem, chr - mem + 1, ft_strlen(chr) - 1);
			free(tmp);
			return (1);
		}
		else
		{
			tmp = mem;
			*line = ft_strdup(mem);
			free(tmp);
			mem = NULL;
		}
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret <= 0)
			return (ret);
		buff[ret] = 0;
		chr = ft_strchr(buff, '\n');
		if (chr != NULL)
		{
			tmp = *line;
			*line = ft_strjoin(*line, ft_strsub(buff, 0, chr - buff));
			if (tmp)
				free(tmp);
			mem = ft_strsub(chr + 1, 0, ft_strlen(chr + 1));
			return (1);
		}
		else
		{
			tmp = *line;
			*line = ft_strjoin(*line, buff);
			if (tmp)
				free(tmp);
		}
	}
	return (ret == 0 ? 0 : 1);
}
