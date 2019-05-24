/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:32:57 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/24 14:57:40 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_replacechr(char	**str, char f, char r)
{
	char	*ptr;

	if ((ptr = strchr(*str, f)) == NULL)
		return (NULL);
	*ptr = r;
	return (ptr);
}

char	*ft_strdupdel(char **str)
{
	char	*tmp;

	tmp = ft_strdup(*str);
	ft_strdel(str);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*fd_arr[FD_MAX];
	char			*ptr;
	char			*tmp;
	int				ret;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	if (fd_arr[fd] == NULL)
		fd_arr[fd] = ft_strnew(0);
	while (strchr(fd_arr[fd], '\n') == NULL)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == 0)
			break;
		tmp = ft_strjoin(fd_arr[fd], buff);
		ft_strdel(&fd_arr[fd]);
		fd_arr[fd] = ft_strdupdel(&tmp);
		if (fd_arr[fd][0] == '\0')
			return (0);
	}
	if ((ptr = ft_replacechr(&fd_arr[fd],'\n','\0')) != NULL)
	{	
		tmp = ft_strdup(ptr + 1);
		*line = ft_strdupdel(&fd_arr[fd]);
		if (tmp != NULL)
			fd_arr[fd] = ft_strdupdel(&tmp);
	}else
	{
		*line = ft_strdupdel(&fd_arr[fd]);
		return (0);
	}
	return (1);
}
