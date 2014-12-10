/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:26:34 by laime             #+#    #+#             */
/*   Updated: 2014/12/10 15:54:44 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft/libft.h"

int		get_next_line(int fd, char **line)
{
	static char	*save = 0;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	*line = save;
	if (ft_strchr(save, '\n'))
	{
		*line = ft_strsub(save, 0, ft_strchr(save, '\n') - save);
		save = ft_strchr(save, '\n') + 1;
		return (1);
	}
	while ((ret = read(fd, &buf, BUFF_SIZE)))
	{
		if (ret < 1)
			return (ret);
		if (ft_strchr(buf, '\n'))
		{
			save = ft_strdup(ft_strchr(buf, '\n') + 1);
			*line = ft_strjoin(*line, buf);
			*line = ft_strsub(*line, 0, ft_strchr(*line, '\n') - *line);
			return (1);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}
